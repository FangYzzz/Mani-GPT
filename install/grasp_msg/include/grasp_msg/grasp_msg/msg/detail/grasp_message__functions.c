// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice
#include "grasp_msg/msg/detail/grasp_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `q_buf`
#include "grasp_msg/msg/detail/joint_pos__functions.h"

bool
grasp_msg__msg__GraspMessage__init(grasp_msg__msg__GraspMessage * msg)
{
  if (!msg) {
    return false;
  }
  // q_buf
  if (!grasp_msg__msg__JointPos__Sequence__init(&msg->q_buf, 0)) {
    grasp_msg__msg__GraspMessage__fini(msg);
    return false;
  }
  return true;
}

void
grasp_msg__msg__GraspMessage__fini(grasp_msg__msg__GraspMessage * msg)
{
  if (!msg) {
    return;
  }
  // q_buf
  grasp_msg__msg__JointPos__Sequence__fini(&msg->q_buf);
}

bool
grasp_msg__msg__GraspMessage__are_equal(const grasp_msg__msg__GraspMessage * lhs, const grasp_msg__msg__GraspMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // q_buf
  if (!grasp_msg__msg__JointPos__Sequence__are_equal(
      &(lhs->q_buf), &(rhs->q_buf)))
  {
    return false;
  }
  return true;
}

bool
grasp_msg__msg__GraspMessage__copy(
  const grasp_msg__msg__GraspMessage * input,
  grasp_msg__msg__GraspMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // q_buf
  if (!grasp_msg__msg__JointPos__Sequence__copy(
      &(input->q_buf), &(output->q_buf)))
  {
    return false;
  }
  return true;
}

grasp_msg__msg__GraspMessage *
grasp_msg__msg__GraspMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__GraspMessage * msg = (grasp_msg__msg__GraspMessage *)allocator.allocate(sizeof(grasp_msg__msg__GraspMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_msg__msg__GraspMessage));
  bool success = grasp_msg__msg__GraspMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_msg__msg__GraspMessage__destroy(grasp_msg__msg__GraspMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_msg__msg__GraspMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_msg__msg__GraspMessage__Sequence__init(grasp_msg__msg__GraspMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__GraspMessage * data = NULL;

  if (size) {
    data = (grasp_msg__msg__GraspMessage *)allocator.zero_allocate(size, sizeof(grasp_msg__msg__GraspMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_msg__msg__GraspMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_msg__msg__GraspMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
grasp_msg__msg__GraspMessage__Sequence__fini(grasp_msg__msg__GraspMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      grasp_msg__msg__GraspMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

grasp_msg__msg__GraspMessage__Sequence *
grasp_msg__msg__GraspMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__GraspMessage__Sequence * array = (grasp_msg__msg__GraspMessage__Sequence *)allocator.allocate(sizeof(grasp_msg__msg__GraspMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_msg__msg__GraspMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_msg__msg__GraspMessage__Sequence__destroy(grasp_msg__msg__GraspMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_msg__msg__GraspMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_msg__msg__GraspMessage__Sequence__are_equal(const grasp_msg__msg__GraspMessage__Sequence * lhs, const grasp_msg__msg__GraspMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_msg__msg__GraspMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_msg__msg__GraspMessage__Sequence__copy(
  const grasp_msg__msg__GraspMessage__Sequence * input,
  grasp_msg__msg__GraspMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_msg__msg__GraspMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_msg__msg__GraspMessage * data =
      (grasp_msg__msg__GraspMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_msg__msg__GraspMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_msg__msg__GraspMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_msg__msg__GraspMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
