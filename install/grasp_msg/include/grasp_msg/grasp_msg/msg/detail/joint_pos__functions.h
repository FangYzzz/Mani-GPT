// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__JOINT_POS__FUNCTIONS_H_
#define GRASP_MSG__MSG__DETAIL__JOINT_POS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "grasp_msg/msg/rosidl_generator_c__visibility_control.h"

#include "grasp_msg/msg/detail/joint_pos__struct.h"

/// Initialize msg/JointPos message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * grasp_msg__msg__JointPos
 * )) before or use
 * grasp_msg__msg__JointPos__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__init(grasp_msg__msg__JointPos * msg);

/// Finalize msg/JointPos message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
void
grasp_msg__msg__JointPos__fini(grasp_msg__msg__JointPos * msg);

/// Create msg/JointPos message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * grasp_msg__msg__JointPos__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
grasp_msg__msg__JointPos *
grasp_msg__msg__JointPos__create();

/// Destroy msg/JointPos message.
/**
 * It calls
 * grasp_msg__msg__JointPos__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
void
grasp_msg__msg__JointPos__destroy(grasp_msg__msg__JointPos * msg);

/// Check for msg/JointPos message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__are_equal(const grasp_msg__msg__JointPos * lhs, const grasp_msg__msg__JointPos * rhs);

/// Copy a msg/JointPos message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__copy(
  const grasp_msg__msg__JointPos * input,
  grasp_msg__msg__JointPos * output);

/// Initialize array of msg/JointPos messages.
/**
 * It allocates the memory for the number of elements and calls
 * grasp_msg__msg__JointPos__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__Sequence__init(grasp_msg__msg__JointPos__Sequence * array, size_t size);

/// Finalize array of msg/JointPos messages.
/**
 * It calls
 * grasp_msg__msg__JointPos__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
void
grasp_msg__msg__JointPos__Sequence__fini(grasp_msg__msg__JointPos__Sequence * array);

/// Create array of msg/JointPos messages.
/**
 * It allocates the memory for the array and calls
 * grasp_msg__msg__JointPos__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
grasp_msg__msg__JointPos__Sequence *
grasp_msg__msg__JointPos__Sequence__create(size_t size);

/// Destroy array of msg/JointPos messages.
/**
 * It calls
 * grasp_msg__msg__JointPos__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
void
grasp_msg__msg__JointPos__Sequence__destroy(grasp_msg__msg__JointPos__Sequence * array);

/// Check for msg/JointPos message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__Sequence__are_equal(const grasp_msg__msg__JointPos__Sequence * lhs, const grasp_msg__msg__JointPos__Sequence * rhs);

/// Copy an array of msg/JointPos messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_grasp_msg
bool
grasp_msg__msg__JointPos__Sequence__copy(
  const grasp_msg__msg__JointPos__Sequence * input,
  grasp_msg__msg__JointPos__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GRASP_MSG__MSG__DETAIL__JOINT_POS__FUNCTIONS_H_
