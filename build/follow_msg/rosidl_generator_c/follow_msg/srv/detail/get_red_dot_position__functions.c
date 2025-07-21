// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice
#include "follow_msg/srv/detail/get_red_dot_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
follow_msg__srv__GetRedDotPosition_Request__init(follow_msg__srv__GetRedDotPosition_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
follow_msg__srv__GetRedDotPosition_Request__fini(follow_msg__srv__GetRedDotPosition_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
follow_msg__srv__GetRedDotPosition_Request__are_equal(const follow_msg__srv__GetRedDotPosition_Request * lhs, const follow_msg__srv__GetRedDotPosition_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
follow_msg__srv__GetRedDotPosition_Request__copy(
  const follow_msg__srv__GetRedDotPosition_Request * input,
  follow_msg__srv__GetRedDotPosition_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

follow_msg__srv__GetRedDotPosition_Request *
follow_msg__srv__GetRedDotPosition_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Request * msg = (follow_msg__srv__GetRedDotPosition_Request *)allocator.allocate(sizeof(follow_msg__srv__GetRedDotPosition_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__srv__GetRedDotPosition_Request));
  bool success = follow_msg__srv__GetRedDotPosition_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__srv__GetRedDotPosition_Request__destroy(follow_msg__srv__GetRedDotPosition_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__srv__GetRedDotPosition_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__init(follow_msg__srv__GetRedDotPosition_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Request * data = NULL;

  if (size) {
    data = (follow_msg__srv__GetRedDotPosition_Request *)allocator.zero_allocate(size, sizeof(follow_msg__srv__GetRedDotPosition_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__srv__GetRedDotPosition_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__srv__GetRedDotPosition_Request__fini(&data[i - 1]);
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
follow_msg__srv__GetRedDotPosition_Request__Sequence__fini(follow_msg__srv__GetRedDotPosition_Request__Sequence * array)
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
      follow_msg__srv__GetRedDotPosition_Request__fini(&array->data[i]);
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

follow_msg__srv__GetRedDotPosition_Request__Sequence *
follow_msg__srv__GetRedDotPosition_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Request__Sequence * array = (follow_msg__srv__GetRedDotPosition_Request__Sequence *)allocator.allocate(sizeof(follow_msg__srv__GetRedDotPosition_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__srv__GetRedDotPosition_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__srv__GetRedDotPosition_Request__Sequence__destroy(follow_msg__srv__GetRedDotPosition_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__srv__GetRedDotPosition_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__are_equal(const follow_msg__srv__GetRedDotPosition_Request__Sequence * lhs, const follow_msg__srv__GetRedDotPosition_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__srv__GetRedDotPosition_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__copy(
  const follow_msg__srv__GetRedDotPosition_Request__Sequence * input,
  follow_msg__srv__GetRedDotPosition_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__srv__GetRedDotPosition_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__srv__GetRedDotPosition_Request * data =
      (follow_msg__srv__GetRedDotPosition_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__srv__GetRedDotPosition_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__srv__GetRedDotPosition_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__srv__GetRedDotPosition_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
follow_msg__srv__GetRedDotPosition_Response__init(follow_msg__srv__GetRedDotPosition_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!geometry_msgs__msg__Point__init(&msg->response)) {
    follow_msg__srv__GetRedDotPosition_Response__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__srv__GetRedDotPosition_Response__fini(follow_msg__srv__GetRedDotPosition_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  geometry_msgs__msg__Point__fini(&msg->response);
}

bool
follow_msg__srv__GetRedDotPosition_Response__are_equal(const follow_msg__srv__GetRedDotPosition_Response * lhs, const follow_msg__srv__GetRedDotPosition_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__srv__GetRedDotPosition_Response__copy(
  const follow_msg__srv__GetRedDotPosition_Response * input,
  follow_msg__srv__GetRedDotPosition_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!geometry_msgs__msg__Point__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

follow_msg__srv__GetRedDotPosition_Response *
follow_msg__srv__GetRedDotPosition_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Response * msg = (follow_msg__srv__GetRedDotPosition_Response *)allocator.allocate(sizeof(follow_msg__srv__GetRedDotPosition_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__srv__GetRedDotPosition_Response));
  bool success = follow_msg__srv__GetRedDotPosition_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__srv__GetRedDotPosition_Response__destroy(follow_msg__srv__GetRedDotPosition_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__srv__GetRedDotPosition_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__init(follow_msg__srv__GetRedDotPosition_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Response * data = NULL;

  if (size) {
    data = (follow_msg__srv__GetRedDotPosition_Response *)allocator.zero_allocate(size, sizeof(follow_msg__srv__GetRedDotPosition_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__srv__GetRedDotPosition_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__srv__GetRedDotPosition_Response__fini(&data[i - 1]);
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
follow_msg__srv__GetRedDotPosition_Response__Sequence__fini(follow_msg__srv__GetRedDotPosition_Response__Sequence * array)
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
      follow_msg__srv__GetRedDotPosition_Response__fini(&array->data[i]);
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

follow_msg__srv__GetRedDotPosition_Response__Sequence *
follow_msg__srv__GetRedDotPosition_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__srv__GetRedDotPosition_Response__Sequence * array = (follow_msg__srv__GetRedDotPosition_Response__Sequence *)allocator.allocate(sizeof(follow_msg__srv__GetRedDotPosition_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__srv__GetRedDotPosition_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__srv__GetRedDotPosition_Response__Sequence__destroy(follow_msg__srv__GetRedDotPosition_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__srv__GetRedDotPosition_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__are_equal(const follow_msg__srv__GetRedDotPosition_Response__Sequence * lhs, const follow_msg__srv__GetRedDotPosition_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__srv__GetRedDotPosition_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__copy(
  const follow_msg__srv__GetRedDotPosition_Response__Sequence * input,
  follow_msg__srv__GetRedDotPosition_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__srv__GetRedDotPosition_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__srv__GetRedDotPosition_Response * data =
      (follow_msg__srv__GetRedDotPosition_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__srv__GetRedDotPosition_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__srv__GetRedDotPosition_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__srv__GetRedDotPosition_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
