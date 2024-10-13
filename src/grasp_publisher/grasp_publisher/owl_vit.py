# -*- coding: utf-8 -*-
import sys
import os     

# sys.path.append('big_vision/')
sys.path.append('./src/grasp_publisher/grasp_publisher/big_vision')
sys.path.append('./src/grasp_publisher/grasp_publisher/ik.py')

# !echo "Done."


import jax
from matplotlib import pyplot as plt
import numpy as np
from scenic.projects.owl_vit import configs
from scenic.projects.owl_vit import models
from scipy.special import expit as sigmoid
import skimage
from skimage import io as skimage_io
from skimage import transform as skimage_transform

import io
from PIL import Image
import matplotlib.pyplot as plt
import tensorflow as tf




def prediction(module, variables, input_image, tokenized_queries, text_queries, crop, cx_=0, cy_=0, original_image=None, width_ =0, height_=0):
    
    jitted = jax.jit(module.apply, static_argnames=('train',)) 
    
    # Note: The model expects a batch dimension.
    predictions = jitted(
        variables,
        input_image[None, ...],
        tokenized_queries[None, ...],
        train=False)

    # Remove batch dimension and convert to numpy:
    predictions = jax.tree_util.tree_map(lambda x: np.array(x[0]), predictions)


    """# Plot predictions"""

    score_threshold = 0.2   # initial 0.2

    logits = predictions['pred_logits'][..., :len(text_queries)]       # Remove padding
    scores = sigmoid(np.max(logits, axis=-1))
    labels = np.argmax(predictions['pred_logits'], axis=-1)
    boxes = predictions['pred_boxes']


    if(crop==False):
        fig, ax = plt.subplots(1, 1, figsize=(8, 8))
        ax.imshow(original_image, extent=(0, 1, 1, 0))   
        ax.set_axis_off()

    for score, box, label in zip(scores, boxes, labels):
        if score < score_threshold:
            continue
        
        cx, cy, w, h = box
        if crop == True:                       
            img_height, img_width, _ = input_image.shape
            print("original padding image:", img_height, img_width)
            print("crop = True: cx, cy, w, h: ", cx, cy, w, h)
            
            left = int((cx - w / 2) * img_width)
            upper = int((cy - h / 2) * img_height)
            right = int((cx + w / 2) * img_width)
            lower = int((cy + h / 2) * img_height)

            # Crop the image
            cropped_image_array = input_image[upper:lower, left:right]

            # Convert the cropped NumPy array to a Pillow image object
            cropped_image = Image.fromarray((cropped_image_array * 255).astype(np.uint8))

            cropped_image.save(os.path.join('./src/grasp_publisher/grasp_publisher/camera_capture/lab/cropped_image0.png'))    

            
            height_c, width_c,_= cropped_image_array.shape
            print("croped image:", height_c, width_c)
        
            return input_image, cx, cy, w, h, height_c, width_c
        
        else:
            cx, cy, w, h = box
            # img_height, img_width, _ = input_image.shape
            img_height_, img_width_, _ = original_image.shape
            # print(img_height, img_width, img_height_, img_width_)

            size = max(height_, width_)
            cx = cx*size/width_

            cx = cx_ - 0.5 * width_ / img_width_ + cx * width_ / img_width_
            cy = cy * size / height_
            cy = cy_ - 0.5 * height_ / img_height_ + cy * height_ / img_height_

            w = w * size / img_width_
            h = h * size / img_height_
            
            print("crop = False: cx, cy, w, h: ", cx, cy, w, h)
            ax.plot([cx - w / 2, cx + w / 2, cx + w / 2, cx - w / 2, cx - w / 2],
                [cy - h / 2, cy - h / 2, cy + h / 2, cy + h / 2, cy - h / 2], 'r')
            ax.text(
                cx - w / 2,
                cy + h / 2 + 0.015,
                f'{text_queries[label]}: {score:1.2f}',
                ha='left',
                va='top',
                color='red',
                bbox={
                    'facecolor': 'white',
                    'edgecolor': 'red',
                    'boxstyle': 'square,pad=.3'
                })
            plt.savefig(os.path.join('./src/grasp_publisher/grasp_publisher/camera_capture/lab/cropped_image0_1.png'))                     
            
            # plt.show()  
            return cx, cy, w, h
            
        


def detect_grasp_name(grasp_name, crop, cx_=0, cy_=0, original_padding_image=None, height=0, width=0):

    """# Choose config"""

    config = configs.owl_v2_clip_b16.get_config(init_mode='canonical_checkpoint')


    """# Load the model and variables"""

    module = models.TextZeroShotDetectionModule(
        body_configs=config.model.body,
        objectness_head_configs=config.model.objectness_head,
        normalize=config.model.normalize,
        box_bias=config.model.box_bias)
    variables = module.load_variables(config.init_from.checkpoint_path)


    """# Prepare image"""

    # filepath = camera_capture.zed()                                                                           
    # zed()

    # Load example image:
    if crop == True:
        filename_input = os.path.join('./src/grasp_publisher/grasp_publisher/camera_capture/lab/ZED_image0.png')               

        
    else:
        filename_input = os.path.join('./src/grasp_publisher/grasp_publisher/camera_capture/lab/cropped_image0.png')         
    

    image_uint8 = skimage_io.imread(filename_input)
    image = image_uint8.astype(np.float32) / 255.0
    # print(image.shape)

    if image.shape[2] == 4:                                                                              # astronaut(512,512,3) ZED(1080,1920,4)
        image = image[:, :, :3]
    # print(image.shape)

    # Pad to square with gray pixels on bottom and right:
    h, w, _ = image.shape
    size = max(h, w)
    image_padded = np.pad(
        image, ((0, size - h), (0, size - w), (0, 0)), constant_values=0.5)

    # Resize to model input size:
    input_image = skimage.transform.resize(
        image_padded,
        (config.dataset_configs.input_size, config.dataset_configs.input_size),
        anti_aliasing=True)



    """# Prepare text queries"""

    # grasp_name = GPT.gpt_dialogue()                                               
    text_queries = [grasp_name]                                             
    # text_queries = ['fork']


    tokenized_queries = np.array([
        module.tokenize(q, config.dataset_configs.max_query_length)
        for q in text_queries
    ])

    # Pad tokenized queries to avoid recompilation if number of queries changes:
    tokenized_queries = np.pad(
        tokenized_queries,
        pad_width=((0, 100 - len(text_queries)), (0, 0)),
        constant_values=0)

    if crop== True:
        original_padding_image, cx, cy, w, h, height, width = prediction(module, variables, input_image, tokenized_queries, text_queries, crop)
        return original_padding_image, cx, cy, w, h, height, width
    else:
        ## sub fig
        cx, cy, w, h = prediction(module, variables, input_image, tokenized_queries, text_queries, crop, cx_, cy_, image, width_=width, height_=height)
        return cx, cy, w, h





