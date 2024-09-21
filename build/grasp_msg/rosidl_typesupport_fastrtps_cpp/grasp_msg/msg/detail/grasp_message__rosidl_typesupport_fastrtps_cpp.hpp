// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "grasp_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "grasp_msg/msg/detail/grasp_message__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace grasp_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
cdr_serialize(
  const grasp_msg::msg::GraspMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  grasp_msg::msg::GraspMessage & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
get_serialized_size(
  const grasp_msg::msg::GraspMessage & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
max_serialized_size_GraspMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace grasp_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, grasp_msg, msg, GraspMessage)();

#ifdef __cplusplus
}
#endif

#endif  // GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
