// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grasp_msg/msg/detail/joint_pos__rosidl_typesupport_introspection_c.h"
#include "grasp_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grasp_msg/msg/detail/joint_pos__functions.h"
#include "grasp_msg/msg/detail/joint_pos__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_msg__msg__JointPos__init(message_memory);
}

void grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_fini_function(void * message_memory)
{
  grasp_msg__msg__JointPos__fini(message_memory);
}

size_t grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__size_function__JointPos__joint_pos(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_const_function__JointPos__joint_pos(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_function__JointPos__joint_pos(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__fetch_function__JointPos__joint_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_const_function__JointPos__joint_pos(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__assign_function__JointPos__joint_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_function__JointPos__joint_pos(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_member_array[1] = {
  {
    "joint_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(grasp_msg__msg__JointPos, joint_pos),  // bytes offset in struct
    NULL,  // default value
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__size_function__JointPos__joint_pos,  // size() function pointer
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_const_function__JointPos__joint_pos,  // get_const(index) function pointer
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__get_function__JointPos__joint_pos,  // get(index) function pointer
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__fetch_function__JointPos__joint_pos,  // fetch(index, &value) function pointer
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__assign_function__JointPos__joint_pos,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_members = {
  "grasp_msg__msg",  // message namespace
  "JointPos",  // message name
  1,  // number of fields
  sizeof(grasp_msg__msg__JointPos),
  grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_member_array,  // message members
  grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_type_support_handle = {
  0,
  &grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_msg, msg, JointPos)() {
  if (!grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_type_support_handle.typesupport_identifier) {
    grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_msg__msg__JointPos__rosidl_typesupport_introspection_c__JointPos_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
