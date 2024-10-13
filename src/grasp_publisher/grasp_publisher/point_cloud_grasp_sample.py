import sys

from grasp_publisher.GIGA.src.giga.perception import *
from grasp_publisher.GIGA.src.giga.utils.implicit import get_mesh_pose_list_from_world, as_mesh#, get_scene_from_mesh_pose_list
from grasp_publisher.GIGA.src.giga.grasp_sampler import GpgGraspSamplerPcl
from grasp_publisher.GIGA.src.giga.utils import visual
from open3d.visualization import draw_plotly
import trimesh
from grasp_publisher.GIGA.src.vgn.utils.transform import Rotation, Transform
import open3d as o3d
import numpy as np
from scipy.spatial.transform import Rotation as R



def grasppart_rgbd_to_pc(rgb_image, depth_image, fx, fy, cx_cam, cy_cam, rect_cx, rect_cy, rect_w, rect_h):
    if rgb_image.shape[2] == 4:                                                                 
        rgb_image = rgb_image[:, :, :3]

    extrinsic_rotation_x = R.from_quat([0.948, 0, 0, -0.317]).as_matrix()                        # X 217
    extrinsic_rotation_z = R.from_quat([0, 0, 0.707, 0.707]).as_matrix()                         # Z 90
    extrinsic_rotation = extrinsic_rotation_z@ extrinsic_rotation_x
    extrinsic_translation = np.array([1.15, 0.04, 0.41])                                        # camera1: [1.05, -0.03, 0.45]
    depth_image = depth_image / 2500.0

    # in-hand camera
    # extrinsic_rotation_x = R.from_quat([0.985, 0, 0, 0.174]).as_matrix()                          # X 127
    # extrinsic_rotation_z = R.from_quat([0, 0, 0.707, 0.707]).as_matrix()                          # Z 90
    # extrinsic_rotation = extrinsic_rotation_z@ extrinsic_rotation_x
    # extrinsic_translation = np.array([0.44, -0.03, 1.1])                                          # camera2: [0.44, -0.03, 0.45]
    # depth_image = depth_image / 1000.0

    # Calculate the start and end points of the rectangle
    height, width = depth_image.shape
    x_start = int((rect_cx - rect_w / 2) * width)
    x_end = int((rect_cx + rect_w / 2) * width)
    y_start = int((rect_cy - rect_h / 2) * height)
    y_end = int((rect_cy + rect_h / 2) * height)
    
    # Extract the depth image and RGB image within the rectangular frame
    depth_patch = depth_image[y_start:y_end, x_start:x_end]
    rgb_patch = rgb_image[y_start:y_end, x_start:x_end, :]
    
    # Get the pixel coordinates within the rectangular frame
    u, v = np.meshgrid(np.arange(x_start, x_end), np.arange(y_start, y_end))

    # Convert pixel coordinates to robot coordinates
    Z = depth_patch
    X = (u - cx_cam) * Z / fx
    Y = (v - cy_cam) * Z / fy
    
    # Combine RGB values ​​with robot coordinates
    points = np.stack((X, Y, Z), axis=-1).reshape(-1, 3)
    points = (extrinsic_rotation @ points.T).T + extrinsic_translation                           # external calibration
    colors = rgb_patch.reshape(-1, 3) / 255.0                                                    # Colors are normalized to [0, 1]

    # Remove black points (colors close to [0, 0, 0])
    color_threshold = 0.3                                                                        ### teapot 0.2 eppper 0.15 fryingpan 0.1
    non_black_mask = np.any(colors > color_threshold, axis=1)
    points = points[non_black_mask]
    colors = colors[non_black_mask]

    # Create an Open3D point cloud object
    point_cloud = o3d.geometry.PointCloud()
    point_cloud.points = o3d.utility.Vector3dVector(points)
    point_cloud.colors = o3d.utility.Vector3dVector(colors)
    
    return point_cloud


def draw_point_cloud(rect_cx, rect_cy, rect_w, rect_h):
    rgb_image_path =  "./src/grasp_publisher/grasp_publisher/camera_capture/lab/ZED_image0.png"                   

    rgb_image = o3d.io.read_image(rgb_image_path)
    rgb_image = np.asarray(rgb_image)

    depth_image_path = "./src/grasp_publisher/grasp_publisher/camera_capture/lab/Depth_0.png"                      
        
    depth_image = o3d.io.read_image(depth_image_path)
    depth_image = np.asarray(depth_image)


    fx, fy = 1057.35, 1056.91
    cx_cam, cy_cam = 1082.06, 637.621
    rect_cx = rect_cx                                                                            
    rect_cy = rect_cy * 1920.0 / 1080.0                                                          
    rect_w = rect_w                                                                              
    rect_h = rect_h * 1920.0 / 1080.0                                                            

    point_cloud = grasppart_rgbd_to_pc(rgb_image, depth_image, fx, fy, cx_cam, cy_cam, rect_cx, rect_cy, rect_w, rect_h)

    draw_plotly([point_cloud])                                                                   # display point cloud on web page
    # o3d.visualization.draw_geometries([point_cloud])

    return point_cloud


def get_GraspSample(rect_cx, rect_cy, rect_w, rect_h):
    point_cloud = draw_point_cloud(rect_cx, rect_cy, rect_w, rect_h)

    num_parallel_workers = 1
    num_grasps = 30

    sampler = GpgGraspSamplerPcl(0.05)                   # Franka finger depth is actually a little less than 0.05m

    grasps, grasps_trans, grasps_rot = sampler.sample_grasps_parallel(point_cloud, 
                                                                    num_parallel=num_parallel_workers,
                                                                    num_grasps=num_grasps, 
                                                                    max_num_samples=80,
                                                                    safety_dis_above_table=0.003,      # 0.003
                                                                    show_final_grasps=False)

    print("len of grasps", len(grasps))

    grasps_scene = trimesh.Scene()

    rotation_matrix = R.from_quat(grasps_rot)
    rotation = rotation_matrix.as_euler('xyz', degrees=True)

    sorted_indices = sorted(range(len(rotation)), key=lambda i: np.square(rotation[i][0]-180) + np.square(rotation[i][1])) # (x-180)^2 + y^2 : small->large      + np.square(rotation[i][2])

    grasps = [grasps[i] for i in sorted_indices]
    grasps_trans = [grasps_trans[i] for i in sorted_indices]
    grasps_rot = [grasps_rot[i] for i in sorted_indices]
    rotation = [rotation[i] for i in sorted_indices]

    grasp_mesh_list = [visual.grasp2mesh(g, score=1) for g in grasps]
    for i, g_mesh in enumerate(grasp_mesh_list):
        grasps_scene.add_geometry(g_mesh, node_name=f'grasp{i}')
        if(i>=2):
            break
    draw_plotly([point_cloud, as_mesh(grasps_scene).as_open3d])

    grasps_trans = np.vstack(grasps_trans)
    rotation = np.vstack(rotation)
    np.set_printoptions(suppress=True)
    print("grasps position:\n",grasps_trans, "\ngrasps rotation(euler angles):\n", rotation)


    return grasps_trans, grasps_rot       # return grasps_rot is still quaternion, rotation is euler angles










