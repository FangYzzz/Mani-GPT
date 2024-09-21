// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grasp_msg/msg/detail/grasp_message__rosidl_typesupport_introspection_c.h"
#include "grasp_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grasp_msg/msg/detail/grasp_message__functions.h"
#include "grasp_msg/msg/detail/grasp_message__struct.h"


// Include directives for member types
// Member `q_buf`
#include "grasp_msg/msg/joint_pos.h"
// Member `q_buf`
#include "grasp_msg/msg/detail/joint_pos__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_msg__msg__GraspMessage__init(message_memory);
}

void grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_fini_function(void * message_memory)
{
  grasp_msg__msg__GraspMessage__fini(message_memory);
}

size_t grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__size_function__GraspMessage__q_buf(
  const void * untyped_member)
{
  const grasp_msg__msg__JointPos__Sequence * member =
    (const grasp_msg__msg__JointPos__Sequence *)(untyped_member);
  return member->size;
}

const void * grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_const_function__GraspMessage__q_buf(
  const void * untyped_member, size_t index)
{
  const grasp_msg__msg__JointPos__Sequence * member =
    (const grasp_msg__msg__JointPos__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_function__GraspMessage__q_buf(
  void * untyped_member, size_t index)
{
  grasp_msg__msg__JointPos__Sequence * member =
    (grasp_msg__msg__JointPos__Sequence *)(untyped_member);
  return &member->data[index];
}

void grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__fetch_function__GraspMessage__q_buf(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const grasp_msg__msg__JointPos * item =
    ((const grasp_msg__msg__JointPos *)
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_const_function__GraspMessage__q_buf(untyped_member, index));
  grasp_msg__msg__JointPos * value =
    (grasp_msg__msg__JointPos *)(untyped_value);
  *value = *item;
}

void grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__assign_function__GraspMessage__q_buf(
  void * untyped_member, size_t index, const void * untyped_value)
{
  grasp_msg__msg__JointPos * item =
    ((grasp_msg__msg__JointPos *)
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_function__GraspMessage__q_buf(untyped_member, index));
  const grasp_msg__msg__JointPos * value =
    (const grasp_msg__msg__JointPos *)(untyped_value);
  *item = *value;
}

bool grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__resize_function__GraspMessage__q_buf(
  void * untyped_member, size_t size)
{
  grasp_msg__msg__JointPos__Sequence * member =
    (grasp_msg__msg__JointPos__Sequence *)(untyped_member);
  grasp_msg__msg__JointPos__Sequence__fini(member);
  return grasp_msg__msg__JointPos__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_member_array[1] = {
  {
    "q_buf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_msg__msg__GraspMessage, q_buf),  // bytes offset in struct
    NULL,  // default value
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__size_function__GraspMessage__q_buf,  // size() function pointer
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_const_function__GraspMessage__q_buf,  // get_const(index) function pointer
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__get_function__GraspMessage__q_buf,  // get(index) function pointer
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__fetch_function__GraspMessage__q_buf,  // fetch(index, &value) function pointer
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__assign_function__GraspMessage__q_buf,  // assign(index, value) function pointer
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__resize_function__GraspMessage__q_buf  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_members = {
  "grasp_msg__msg",  // message namespace
  "GraspMessage",  // message name
  1,  // number of fields
  sizeof(grasp_msg__msg__GraspMessage),
  grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_member_array,  // message members
  grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_type_support_handle = {
  0,
  &grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_msg, msg, GraspMessage)() {
  grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_msg, msg, JointPos)();
  if (!grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_type_support_handle.typesupport_identifier) {
    grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_msg__msg__GraspMessage__rosidl_typesupport_introspection_c__GraspMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
