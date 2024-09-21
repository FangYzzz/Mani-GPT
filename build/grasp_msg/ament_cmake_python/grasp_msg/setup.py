from setuptools import find_packages
from setuptools import setup

setup(
    name='grasp_msg',
    version='0.0.0',
    packages=find_packages(
        include=('grasp_msg', 'grasp_msg.*')),
)
