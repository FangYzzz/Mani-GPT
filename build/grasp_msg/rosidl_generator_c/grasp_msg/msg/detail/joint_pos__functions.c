// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice
#include "grasp_msg/msg/detail/joint_pos__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
grasp_msg__msg__JointPos__init(grasp_msg__msg__JointPos * msg)
{
  if (!msg) {
    return false;
  }
  // joint_pos
  return true;
}

void
grasp_msg__msg__JointPos__fini(grasp_msg__msg__JointPos * msg)
{
  if (!msg) {
    return;
  }
  // joint_pos
}

bool
grasp_msg__msg__JointPos__are_equal(const grasp_msg__msg__JointPos * lhs, const grasp_msg__msg__JointPos * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_pos
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->joint_pos[i] != rhs->joint_pos[i]) {
      return false;
    }
  }
  return true;
}

bool
grasp_msg__msg__JointPos__copy(
  const grasp_msg__msg__JointPos * input,
  grasp_msg__msg__JointPos * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_pos
  for (size_t i = 0; i < 7; ++i) {
    output->joint_pos[i] = input->joint_pos[i];
  }
  return true;
}

grasp_msg__msg__JointPos *
grasp_msg__msg__JointPos__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__JointPos * msg = (grasp_msg__msg__JointPos *)allocator.allocate(sizeof(grasp_msg__msg__JointPos), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_msg__msg__JointPos));
  bool success = grasp_msg__msg__JointPos__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_msg__msg__JointPos__destroy(grasp_msg__msg__JointPos * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_msg__msg__JointPos__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_msg__msg__JointPos__Sequence__init(grasp_msg__msg__JointPos__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__JointPos * data = NULL;

  if (size) {
    data = (grasp_msg__msg__JointPos *)allocator.zero_allocate(size, sizeof(grasp_msg__msg__JointPos), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_msg__msg__JointPos__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_msg__msg__JointPos__fini(&data[i - 1]);
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
grasp_msg__msg__JointPos__Sequence__fini(grasp_msg__msg__JointPos__Sequence * array)
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
      grasp_msg__msg__JointPos__fini(&array->data[i]);
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

grasp_msg__msg__JointPos__Sequence *
grasp_msg__msg__JointPos__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_msg__msg__JointPos__Sequence * array = (grasp_msg__msg__JointPos__Sequence *)allocator.allocate(sizeof(grasp_msg__msg__JointPos__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_msg__msg__JointPos__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_msg__msg__JointPos__Sequence__destroy(grasp_msg__msg__JointPos__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_msg__msg__JointPos__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_msg__msg__JointPos__Sequence__are_equal(const grasp_msg__msg__JointPos__Sequence * lhs, const grasp_msg__msg__JointPos__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_msg__msg__JointPos__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_msg__msg__JointPos__Sequence__copy(
  const grasp_msg__msg__JointPos__Sequence * input,
  grasp_msg__msg__JointPos__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_msg__msg__JointPos);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_msg__msg__JointPos * data =
      (grasp_msg__msg__JointPos *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_msg__msg__JointPos__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_msg__msg__JointPos__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_msg__msg__JointPos__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
