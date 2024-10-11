# Installation 
![sys-vesrion](https://img.shields.io/badge/Ubuntu-22.04-blue) ![Python](https://img.shields.io/badge/Python-3.10-red) ![ROS 2](https://img.shields.io/badge/ROS2-Humble-orange)

The code depends on the code of [owl-it](https://github.com/google-research/scenic/tree/main/scenic/projects/owl_vit#installation), [detic](https://github.com/facebookresearch/Detic) and [GIGA](https://github.com/pearl-robot-lab/GIGA).


```
mkdir -p your_folder/src
cd your_folder/src

ros2 pkg create --build-type ament_python <package_name>

cd package_name/package_name

```
## install owl-it
```
git clone https://github.com/google-research/scenic.git
cd ~/scenic
python -m pip install -vq .
python -m pip install -r scenic/projects/owl_vit/requirements.txt

# For GPU support:
pip install --upgrade "jax[cuda]" -f https://storage.googleapis.com/jax-releases/jax_cuda_releases.html
```
---
## install Detic
[https://github.com/facebookresearch/Detic/blob/main/docs/INSTALL.md](https://github.com/facebookresearch/Detic/blob/main/docs/INSTALL.md)

## install GIGA

1. Install packages list in [requirements.txt](requirements.txt). Then install `torch-scatter` following [here](https://github.com/rusty1s/pytorch_scatter), based on `pytorch` version and `cuda` version.

2. Go to the root directory and install the project locally using `pip`

```
pip install -e .
```

3. Build ConvONets dependents by running `python scripts/convonet_setup.py build_ext --inplace`.

4. Download the [data](https://utexas.box.com/s/h3ferwjhuzy6ja8bzcm3nu9xq1wkn94s), then unzip and place the data folder under the repo's root. Pretrained models of GIGA, GIGA-Aff and VGN are in `data/models`.

## ChatGPT API

You need to apply a ChatGPT API key to integrate and use ChatGPT in your code. You can find the tutorial at the link below.
[ChatGPT API](https://platform.openai.com/docs/api-reference/introduction)



# Result

<img src="./assets/videos/banana.gif" alt="005" style="zoom: 70%;" />







