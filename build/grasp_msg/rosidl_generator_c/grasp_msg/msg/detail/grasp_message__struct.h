// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_H_
#define GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'q_buf'
#include "grasp_msg/msg/detail/joint_pos__struct.h"

/// Struct defined in msg/GraspMessage in the package grasp_msg.
typedef struct grasp_msg__msg__GraspMessage
{
  grasp_msg__msg__JointPos__Sequence q_buf;
} grasp_msg__msg__GraspMessage;

// Struct for a sequence of grasp_msg__msg__GraspMessage.
typedef struct grasp_msg__msg__GraspMessage__Sequence
{
  grasp_msg__msg__GraspMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_msg__msg__GraspMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_H_
