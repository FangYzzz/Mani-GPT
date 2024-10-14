# Installation 
![sys-vesrion](https://img.shields.io/badge/Ubuntu-22.04-blue) ![Python](https://img.shields.io/badge/Python-3.10-red) ![ROS 2](https://img.shields.io/badge/ROS2-Humble-orange)

The code depends on the code of [Detic](https://github.com/facebookresearch/Detic), [OWL-ViT](https://github.com/google-research/scenic/tree/main/scenic/projects/owl_vit#installation) and [GIGA](https://github.com/pearl-robot-lab/GIGA).


```
mkdir -p your_folder/src
cd your_folder/src

ros2 pkg create --build-type ament_python <package_name>

cd package_name/package_name
```
## install Detic
[https://github.com/facebookresearch/Detic/blob/main/docs/INSTALL.md](https://github.com/facebookresearch/Detic/blob/main/docs/INSTALL.md)

## install OWL-ViT
```
git clone https://github.com/google-research/scenic.git
cd ~/scenic
python -m pip install -vq .
python -m pip install -r scenic/projects/owl_vit/requirements.txt

# For GPU support:
pip install --upgrade "jax[cuda]" -f https://storage.googleapis.com/jax-releases/jax_cuda_releases.html
```

## install GIGA

1. Install packages list in [requirements.txt](requirements.txt). Then install `torch-scatter` following [here](https://github.com/rusty1s/pytorch_scatter), based on `pytorch` version and `cuda` version.

2. Go to the root directory and install the project locally using `pip`

```
pip install -e .
```

3. Build ConvONets dependent on running `python scripts/convonet_setup.py build_ext --inplace`.

4. Download the [data](https://utexas.box.com/s/h3ferwjhuzy6ja8bzcm3nu9xq1wkn94s), then unzip and place the data folder under the repo's root. Pretrained models of GIGA, GIGA-Aff and VGN are in `data/models`.

## ChatGPT API

You need to apply a ChatGPT API key to integrate and use ChatGPT in your code. You can find the tutorial at the link below.
[ChatGPT API](https://platform.openai.com/docs/api-reference/introduction)

# Execution

```
ros2 run grasp_publisher gpt

ros2 run franka_grasp grasp
```

# Result
grasp banana
---
<img src="./assets/videos/banana.gif" alt="005" style="zoom: 70%;" />

---
grasp spoon
---
<img src="./assets/videos/spoon.gif" alt="005" style="zoom: 70%;" />

---

grasp pepper
---
<img src="./assets/videos/pepper.gif" alt="005" style="zoom: 70%;" />







