import sys
import numpy as np
import pyzed.sl as sl
import cv2




help_string = "[s] Save side by side image [d] Save Depth, [n] Change Depth format, [p] Save Point Cloud, [m] Change Point Cloud format, [q] Quit"
prefix_point_cloud = "Cloud_"
prefix_depth = "Depth_"
path = "/home/yuan/mani_gpt/src/grasp_publisher/grasp_publisher/camera_capture/lab/"
# path = "./"

count_save = 0
mode_point_cloud = 0
mode_depth = 0
point_cloud_format_ext = ".ply"
depth_format_ext = ".png"

def point_cloud_format_name():     # 根据当前模式获取保存点云数据的文件扩展名
    global mode_point_cloud
    if mode_point_cloud > 3:
        mode_point_cloud = 0
    switcher = {
        0: ".xyz",
        1: ".pcd",
        2: ".ply",
        3: ".vtk",
    }
    return switcher.get(mode_point_cloud, "nothing") 
  
def depth_format_name():     # 根据当前模式获取保存深度图数据的文件扩展名
    global mode_depth
    if mode_depth > 2:
        mode_depth = 0
    switcher = {
        0: ".png",
        1: ".pfm",
        2: ".pgm",
    }
    return switcher.get(mode_depth, "nothing") 

def save_point_cloud(zed, filename) :     # 从 ZED 相机获取点云数据, 将数据保存到带有相应扩展名的文件中, 打印保存是否成功的信息
    print("Saving Point Cloud...")
    tmp = sl.Mat()
    zed.retrieve_measure(tmp, sl.MEASURE.XYZRGBA)
    saved = (tmp.write(filename + point_cloud_format_ext) == sl.ERROR_CODE.SUCCESS)
    if saved :
        print("Done")
    else :
        print("Failed... Please check that you have permissions to write on disk")

def save_depth(zed, filename) :     # 从 ZED 相机获取深度图数据, 将数据保存到带有相应扩展名的文件中, 打印保存是否成功的信息
    print("Saving Depth Map...")
    tmp = sl.Mat()
    zed.retrieve_measure(tmp, sl.MEASURE.DEPTH)
    saved = (tmp.write(filename + depth_format_ext) == sl.ERROR_CODE.SUCCESS)
    if saved :
        print("Done")
    else :
        print("Failed... Please check that you have permissions to write on disk")

def save_sbs_image(zed, filename) :     # 从 ZED 相机获取左图像和右图像, 水平拼接两个图像, 将拼接后的图像保存到文件中
    print("Saving Left Image...")

    image_sl_left = sl.Mat()
    zed.retrieve_image(image_sl_left, sl.VIEW.LEFT)
    image_cv_left = image_sl_left.get_data()

    image_sl_right = sl.Mat()
    zed.retrieve_image(image_sl_right, sl.VIEW.RIGHT)
    image_cv_right = image_sl_right.get_data()

    # sbs_image = np.concatenate((image_cv_left, image_cv_right), axis=1)

    # cv2.imwrite(filename, sbs_image)
    cv2.imwrite(filename, image_cv_left)
    print("Done")



def process_key_event(zed, key) :                                      # 0
    global mode_depth
    global mode_point_cloud
    global count_save
    global depth_format_ext
    global point_cloud_format_ext

    if key == 100 or key == 68:                                         # Press 'd' to save Depth image
        save_depth(zed, path + prefix_depth + str(count_save))
        count_save += 1
        return  path + prefix_depth + str(count_save)
    elif key == 110 or key == 78:                                       # Press 'n' to switch Depth format
        mode_depth += 1
        depth_format_ext = depth_format_name()
        print("Depth format: ", depth_format_ext)
    elif key == 112 or key == 80:                                       # Press 'p' to save Point Cloud
        save_point_cloud(zed, path + prefix_point_cloud + str(count_save))
        count_save += 1
        return path + prefix_point_cloud + str(count_save)
    elif key == 109 or key == 77:                                       # Press 'm' to switch Point Cloud format
        mode_point_cloud += 1
        point_cloud_format_ext = point_cloud_format_name()
        print("Point Cloud format: ", point_cloud_format_ext)
    elif key == 104 or key == 72:
        print(help_string)
    elif key == 115:
        save_sbs_image(zed, path + "ZED_image" + str(count_save) + ".png")
        save_depth(zed, path + prefix_depth + str(count_save))
        save_point_cloud(zed, path + prefix_point_cloud + str(count_save))
        
        # count_save += 1

        return path + "ZED_image" + str(count_save) + ".png"
    else:
        a = 0

def process_key_event(zed) :
    save_sbs_image(zed, path + "ZED_image" + str(count_save) + ".png")
    save_depth(zed, path + prefix_depth + str(count_save))
    save_point_cloud(zed, path + prefix_point_cloud + str(count_save))

    return path + "ZED_image" + str(count_save) + ".png"


def print_help() :
    print(" Press 's' to save Left Image, Depth image and Point Cloud")
    # print(" Press 's' to save Side by side images")
    # print(" Press 'p' to save Point Cloud")
    # print(" Press 'd' to save Depth image")
    # print(" Press 'm' to switch Point Cloud format")
    # print(" Press 'n' to switch Depth format")


def zed():
    # Create a ZED camera object
    zed = sl.Camera()

    # Set configuration parameters
    input_type = sl.InputType()
    if len(sys.argv) >= 2 :
        input_type.set_from_svo_file(sys.argv[1])
    init = sl.InitParameters(input_t=input_type)
    init.camera_resolution = sl.RESOLUTION.HD1080
    init.depth_mode = sl.DEPTH_MODE.PERFORMANCE
    init.coordinate_units = sl.UNIT.MILLIMETER

    # Open the camera
    err = zed.open(init)
    if err != sl.ERROR_CODE.SUCCESS :
        print(repr(err))
        zed.close()
        exit(1)

    # Display help in console
    # print_help()                                                     # 0

    # Set runtime parameters after opening the camera
    runtime = sl.RuntimeParameters()

    # Prepare new image size to retrieve half-resolution images
    image_size = zed.get_camera_information().camera_configuration.resolution
    image_size.width = image_size.width /2
    image_size.height = image_size.height /2

    # Declare your sl.Mat matrices
    image_zed = sl.Mat(image_size.width, image_size.height, sl.MAT_TYPE.U8_C4)
    depth_image_zed = sl.Mat(image_size.width, image_size.height, sl.MAT_TYPE.U8_C4)
    point_cloud = sl.Mat()

    key = ' '
    while key != 113 :
        err = zed.grab(runtime)
        if err == sl.ERROR_CODE.SUCCESS :
            # Retrieve the left image, depth image in the half-resolution
            zed.retrieve_image(image_zed, sl.VIEW.LEFT, sl.MEM.CPU, image_size)
            zed.retrieve_image(depth_image_zed, sl.VIEW.DEPTH, sl.MEM.CPU, image_size)
            # Retrieve the RGBA point cloud in half resolution
            zed.retrieve_measure(point_cloud, sl.MEASURE.XYZRGBA, sl.MEM.CPU, image_size)

            # To recover data from sl.Mat to use it with opencv, use the get_data() method
            # It returns a numpy array that can be used as a matrix with opencv
            image_ocv = image_zed.get_data()
            depth_image_ocv = depth_image_zed.get_data()

            # cv2.imshow("Image", image_ocv)                           # 0
            # cv2.imshow("Depth", depth_image_ocv)

            key = cv2.waitKey(10)

            # filepath = process_key_event(zed, key)                   # 0
            filepath = process_key_event(zed)

            if filepath != None:
                cv2.destroyAllWindows()
                zed.close()
                return filepath

    # cv2.destroyAllWindows()
    # zed.close()

    # print("\nFINISH")
    # return filepath





