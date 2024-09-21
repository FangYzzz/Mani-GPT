from setuptools import setup, find_packages, find_namespace_packages
# package2=find_packages(include=['grasp_publisher']) 

package_name = 'grasp_publisher'


setup(
    name=package_name,
    version='0.0.0',
    # packages=find_packages(exclude=['grasp_publisher']), 
    packages=find_namespace_packages(where='.'),
    package_dir={"": "."},

    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yuan',
    maintainer_email='fangyuan_fiona@163.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'gpt = grasp_publisher.GPT: main',  
        ],
    },
)
