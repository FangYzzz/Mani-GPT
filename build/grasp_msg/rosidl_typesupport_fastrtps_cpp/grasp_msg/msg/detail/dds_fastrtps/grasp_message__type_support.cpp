// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice
#include "grasp_msg/msg/detail/grasp_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "grasp_msg/msg/detail/grasp_message__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace grasp_msg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const grasp_msg::msg::JointPos &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  grasp_msg::msg::JointPos &);
size_t get_serialized_size(
  const grasp_msg::msg::JointPos &,
  size_t current_alignment);
size_t
max_serialized_size_JointPos(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace grasp_msg


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: q_buf
  {
    size_t size = ros_message.q_buf.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      grasp_msg::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.q_buf[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  grasp_msg::msg::GraspMessage & ros_message)
{
  // Member: q_buf
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.q_buf.resize(size);
    for (size_t i = 0; i < size; i++) {
      grasp_msg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.q_buf[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
get_serialized_size(
  const grasp_msg::msg::GraspMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: q_buf
  {
    size_t array_size = ros_message.q_buf.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        grasp_msg::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.q_buf[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_grasp_msg
max_serialized_size_GraspMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: q_buf
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        grasp_msg::msg::typesupport_fastrtps_cpp::max_serialized_size_JointPos(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = grasp_msg::msg::GraspMessage;
    is_plain =
      (
      offsetof(DataType, q_buf) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GraspMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const grasp_msg::msg::GraspMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GraspMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grasp_msg::msg::GraspMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GraspMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grasp_msg::msg::GraspMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GraspMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GraspMessage(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GraspMessage__callbacks = {
  "grasp_msg::msg",
  "GraspMessage",
  _GraspMessage__cdr_serialize,
  _GraspMessage__cdr_deserialize,
  _GraspMessage__get_serialized_size,
  _GraspMessage__max_serialized_size
};

static rosidl_message_type_support_t _GraspMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GraspMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace grasp_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_grasp_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<grasp_msg::msg::GraspMessage>()
{
  return &grasp_msg::msg::typesupport_fastrtps_cpp::_GraspMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, grasp_msg, msg, GraspMessage)() {
  return &grasp_msg::msg::typesupport_fastrtps_cpp::_GraspMessage__handle;
}

#ifdef __cplusplus
}
#endif
