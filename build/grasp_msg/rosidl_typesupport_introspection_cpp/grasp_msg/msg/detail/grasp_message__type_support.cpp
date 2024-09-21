// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "grasp_msg/msg/detail/grasp_message__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace grasp_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GraspMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) grasp_msg::msg::GraspMessage(_init);
}

void GraspMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<grasp_msg::msg::GraspMessage *>(message_memory);
  typed_message->~GraspMessage();
}

size_t size_function__GraspMessage__q_buf(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<grasp_msg::msg::JointPos> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GraspMessage__q_buf(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<grasp_msg::msg::JointPos> *>(untyped_member);
  return &member[index];
}

void * get_function__GraspMessage__q_buf(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<grasp_msg::msg::JointPos> *>(untyped_member);
  return &member[index];
}

void fetch_function__GraspMessage__q_buf(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const grasp_msg::msg::JointPos *>(
    get_const_function__GraspMessage__q_buf(untyped_member, index));
  auto & value = *reinterpret_cast<grasp_msg::msg::JointPos *>(untyped_value);
  value = item;
}

void assign_function__GraspMessage__q_buf(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<grasp_msg::msg::JointPos *>(
    get_function__GraspMessage__q_buf(untyped_member, index));
  const auto & value = *reinterpret_cast<const grasp_msg::msg::JointPos *>(untyped_value);
  item = value;
}

void resize_function__GraspMessage__q_buf(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<grasp_msg::msg::JointPos> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GraspMessage_message_member_array[1] = {
  {
    "q_buf",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<grasp_msg::msg::JointPos>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_msg::msg::GraspMessage, q_buf),  // bytes offset in struct
    nullptr,  // default value
    size_function__GraspMessage__q_buf,  // size() function pointer
    get_const_function__GraspMessage__q_buf,  // get_const(index) function pointer
    get_function__GraspMessage__q_buf,  // get(index) function pointer
    fetch_function__GraspMessage__q_buf,  // fetch(index, &value) function pointer
    assign_function__GraspMessage__q_buf,  // assign(index, value) function pointer
    resize_function__GraspMessage__q_buf  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GraspMessage_message_members = {
  "grasp_msg::msg",  // message namespace
  "GraspMessage",  // message name
  1,  // number of fields
  sizeof(grasp_msg::msg::GraspMessage),
  GraspMessage_message_member_array,  // message members
  GraspMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  GraspMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GraspMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GraspMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace grasp_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<grasp_msg::msg::GraspMessage>()
{
  return &::grasp_msg::msg::rosidl_typesupport_introspection_cpp::GraspMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, grasp_msg, msg, GraspMessage)() {
  return &::grasp_msg::msg::rosidl_typesupport_introspection_cpp::GraspMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
