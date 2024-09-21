// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_H_
#define GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/JointPos in the package grasp_msg.
typedef struct grasp_msg__msg__JointPos
{
  double joint_pos[7];
} grasp_msg__msg__JointPos;

// Struct for a sequence of grasp_msg__msg__JointPos.
typedef struct grasp_msg__msg__JointPos__Sequence
{
  grasp_msg__msg__JointPos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_msg__msg__JointPos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_H_
