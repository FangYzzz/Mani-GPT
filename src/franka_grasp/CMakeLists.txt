cmake_minimum_required(VERSION 3.5)
project(franka_grasp)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(grasp_msg REQUIRED)

# find_package(Python3 COMPONENTS Interpreter Development REQUIRED PATHS /usr/)
# find_package(pybind11 REQUIRED PATHS opt/ros/foxy/share/cmake/pybind11)
# include_directories(/opt/ros/foxy/include/pybind11)
# find_package(examples REQUIRED)
find_package(Franka REQUIRED)
add_library(examples_common STATIC
  src/examples_common.cpp
)
ament_target_dependencies(examples_common Franka Eigen3 rclcpp grasp_msg)


include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/franka_grasp                     # Assuming headers are in 'include'
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  # examples/*.h
)

# add_subdirectory(examples)

# add_library(grasp SHARED
#         # include/my_math_lib/my_math_lib.hpp
#         src/grasp.cpp
#         )

# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# add_library(grasp src/grasp.cpp)

# target_include_directories(grasp PUBLIC
# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# $<INSTALL_INTERFACE:include>
# )
add_executable(grasp src/grasp.cpp)	                                   ##### grasp为输入节点后执行的名称，如ros2 run test_c test（前一个test_c为包名，后一个test则为这里的设置的名称，代表具体执行的代码）
target_link_libraries(grasp examples_common)	                         ##### 添加依赖项

# ament_export_targets(grasp HAS_LIBRARY_TARGET)
# ament_export_dependencies(
#   examples_common
# )

install(TARGETS grasp
  DESTINATION lib/${PROJECT_NAME})

ament_package()
