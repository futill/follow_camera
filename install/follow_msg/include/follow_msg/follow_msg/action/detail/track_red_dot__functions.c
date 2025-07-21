// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from follow_msg:action/TrackRedDot.idl
// generated code does not contain a copyright notice
#include "follow_msg/action/detail/track_red_dot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_angles`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
follow_msg__action__TrackRedDot_Goal__init(follow_msg__action__TrackRedDot_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target_angles
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->target_angles, 0)) {
    follow_msg__action__TrackRedDot_Goal__fini(msg);
    return false;
  }
  // is_relative
  return true;
}

void
follow_msg__action__TrackRedDot_Goal__fini(follow_msg__action__TrackRedDot_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target_angles
  geometry_msgs__msg__Point__Sequence__fini(&msg->target_angles);
  // is_relative
}

bool
follow_msg__action__TrackRedDot_Goal__are_equal(const follow_msg__action__TrackRedDot_Goal * lhs, const follow_msg__action__TrackRedDot_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_angles
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->target_angles), &(rhs->target_angles)))
  {
    return false;
  }
  // is_relative
  if (lhs->is_relative != rhs->is_relative) {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_Goal__copy(
  const follow_msg__action__TrackRedDot_Goal * input,
  follow_msg__action__TrackRedDot_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_angles
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->target_angles), &(output->target_angles)))
  {
    return false;
  }
  // is_relative
  output->is_relative = input->is_relative;
  return true;
}

follow_msg__action__TrackRedDot_Goal *
follow_msg__action__TrackRedDot_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Goal * msg = (follow_msg__action__TrackRedDot_Goal *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_Goal));
  bool success = follow_msg__action__TrackRedDot_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_Goal__destroy(follow_msg__action__TrackRedDot_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_Goal__Sequence__init(follow_msg__action__TrackRedDot_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Goal * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_Goal *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_Goal__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_Goal__Sequence__fini(follow_msg__action__TrackRedDot_Goal__Sequence * array)
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
      follow_msg__action__TrackRedDot_Goal__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_Goal__Sequence *
follow_msg__action__TrackRedDot_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Goal__Sequence * array = (follow_msg__action__TrackRedDot_Goal__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_Goal__Sequence__destroy(follow_msg__action__TrackRedDot_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_Goal__Sequence__are_equal(const follow_msg__action__TrackRedDot_Goal__Sequence * lhs, const follow_msg__action__TrackRedDot_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_Goal__Sequence__copy(
  const follow_msg__action__TrackRedDot_Goal__Sequence * input,
  follow_msg__action__TrackRedDot_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_Goal * data =
      (follow_msg__action__TrackRedDot_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
follow_msg__action__TrackRedDot_Result__init(follow_msg__action__TrackRedDot_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    follow_msg__action__TrackRedDot_Result__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_Result__fini(follow_msg__action__TrackRedDot_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
follow_msg__action__TrackRedDot_Result__are_equal(const follow_msg__action__TrackRedDot_Result * lhs, const follow_msg__action__TrackRedDot_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_Result__copy(
  const follow_msg__action__TrackRedDot_Result * input,
  follow_msg__action__TrackRedDot_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_Result *
follow_msg__action__TrackRedDot_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Result * msg = (follow_msg__action__TrackRedDot_Result *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_Result));
  bool success = follow_msg__action__TrackRedDot_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_Result__destroy(follow_msg__action__TrackRedDot_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_Result__Sequence__init(follow_msg__action__TrackRedDot_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Result * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_Result *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_Result__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_Result__Sequence__fini(follow_msg__action__TrackRedDot_Result__Sequence * array)
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
      follow_msg__action__TrackRedDot_Result__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_Result__Sequence *
follow_msg__action__TrackRedDot_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Result__Sequence * array = (follow_msg__action__TrackRedDot_Result__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_Result__Sequence__destroy(follow_msg__action__TrackRedDot_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_Result__Sequence__are_equal(const follow_msg__action__TrackRedDot_Result__Sequence * lhs, const follow_msg__action__TrackRedDot_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_Result__Sequence__copy(
  const follow_msg__action__TrackRedDot_Result__Sequence * input,
  follow_msg__action__TrackRedDot_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_Result * data =
      (follow_msg__action__TrackRedDot_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
follow_msg__action__TrackRedDot_Feedback__init(follow_msg__action__TrackRedDot_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
follow_msg__action__TrackRedDot_Feedback__fini(follow_msg__action__TrackRedDot_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
follow_msg__action__TrackRedDot_Feedback__are_equal(const follow_msg__action__TrackRedDot_Feedback * lhs, const follow_msg__action__TrackRedDot_Feedback * rhs)
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
follow_msg__action__TrackRedDot_Feedback__copy(
  const follow_msg__action__TrackRedDot_Feedback * input,
  follow_msg__action__TrackRedDot_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

follow_msg__action__TrackRedDot_Feedback *
follow_msg__action__TrackRedDot_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Feedback * msg = (follow_msg__action__TrackRedDot_Feedback *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_Feedback));
  bool success = follow_msg__action__TrackRedDot_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_Feedback__destroy(follow_msg__action__TrackRedDot_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_Feedback__Sequence__init(follow_msg__action__TrackRedDot_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Feedback * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_Feedback *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_Feedback__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_Feedback__Sequence__fini(follow_msg__action__TrackRedDot_Feedback__Sequence * array)
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
      follow_msg__action__TrackRedDot_Feedback__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_Feedback__Sequence *
follow_msg__action__TrackRedDot_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_Feedback__Sequence * array = (follow_msg__action__TrackRedDot_Feedback__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_Feedback__Sequence__destroy(follow_msg__action__TrackRedDot_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_Feedback__Sequence__are_equal(const follow_msg__action__TrackRedDot_Feedback__Sequence * lhs, const follow_msg__action__TrackRedDot_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_Feedback__Sequence__copy(
  const follow_msg__action__TrackRedDot_Feedback__Sequence * input,
  follow_msg__action__TrackRedDot_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_Feedback * data =
      (follow_msg__action__TrackRedDot_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "follow_msg/action/detail/track_red_dot__functions.h"

bool
follow_msg__action__TrackRedDot_SendGoal_Request__init(follow_msg__action__TrackRedDot_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    follow_msg__action__TrackRedDot_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!follow_msg__action__TrackRedDot_Goal__init(&msg->goal)) {
    follow_msg__action__TrackRedDot_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_SendGoal_Request__fini(follow_msg__action__TrackRedDot_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  follow_msg__action__TrackRedDot_Goal__fini(&msg->goal);
}

bool
follow_msg__action__TrackRedDot_SendGoal_Request__are_equal(const follow_msg__action__TrackRedDot_SendGoal_Request * lhs, const follow_msg__action__TrackRedDot_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!follow_msg__action__TrackRedDot_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_SendGoal_Request__copy(
  const follow_msg__action__TrackRedDot_SendGoal_Request * input,
  follow_msg__action__TrackRedDot_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!follow_msg__action__TrackRedDot_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_SendGoal_Request *
follow_msg__action__TrackRedDot_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Request * msg = (follow_msg__action__TrackRedDot_SendGoal_Request *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_SendGoal_Request));
  bool success = follow_msg__action__TrackRedDot_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_SendGoal_Request__destroy(follow_msg__action__TrackRedDot_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__init(follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Request * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_SendGoal_Request *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_SendGoal_Request__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__fini(follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * array)
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
      follow_msg__action__TrackRedDot_SendGoal_Request__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_SendGoal_Request__Sequence *
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * array = (follow_msg__action__TrackRedDot_SendGoal_Request__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__destroy(follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__are_equal(const follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * lhs, const follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_SendGoal_Request__Sequence__copy(
  const follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * input,
  follow_msg__action__TrackRedDot_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_SendGoal_Request * data =
      (follow_msg__action__TrackRedDot_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
follow_msg__action__TrackRedDot_SendGoal_Response__init(follow_msg__action__TrackRedDot_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    follow_msg__action__TrackRedDot_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_SendGoal_Response__fini(follow_msg__action__TrackRedDot_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
follow_msg__action__TrackRedDot_SendGoal_Response__are_equal(const follow_msg__action__TrackRedDot_SendGoal_Response * lhs, const follow_msg__action__TrackRedDot_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_SendGoal_Response__copy(
  const follow_msg__action__TrackRedDot_SendGoal_Response * input,
  follow_msg__action__TrackRedDot_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_SendGoal_Response *
follow_msg__action__TrackRedDot_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Response * msg = (follow_msg__action__TrackRedDot_SendGoal_Response *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_SendGoal_Response));
  bool success = follow_msg__action__TrackRedDot_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_SendGoal_Response__destroy(follow_msg__action__TrackRedDot_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__init(follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Response * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_SendGoal_Response *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_SendGoal_Response__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__fini(follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * array)
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
      follow_msg__action__TrackRedDot_SendGoal_Response__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_SendGoal_Response__Sequence *
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * array = (follow_msg__action__TrackRedDot_SendGoal_Response__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__destroy(follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__are_equal(const follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * lhs, const follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_SendGoal_Response__Sequence__copy(
  const follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * input,
  follow_msg__action__TrackRedDot_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_SendGoal_Response * data =
      (follow_msg__action__TrackRedDot_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
follow_msg__action__TrackRedDot_GetResult_Request__init(follow_msg__action__TrackRedDot_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    follow_msg__action__TrackRedDot_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_GetResult_Request__fini(follow_msg__action__TrackRedDot_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
follow_msg__action__TrackRedDot_GetResult_Request__are_equal(const follow_msg__action__TrackRedDot_GetResult_Request * lhs, const follow_msg__action__TrackRedDot_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_GetResult_Request__copy(
  const follow_msg__action__TrackRedDot_GetResult_Request * input,
  follow_msg__action__TrackRedDot_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_GetResult_Request *
follow_msg__action__TrackRedDot_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Request * msg = (follow_msg__action__TrackRedDot_GetResult_Request *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_GetResult_Request));
  bool success = follow_msg__action__TrackRedDot_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_GetResult_Request__destroy(follow_msg__action__TrackRedDot_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__init(follow_msg__action__TrackRedDot_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Request * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_GetResult_Request *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_GetResult_Request__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__fini(follow_msg__action__TrackRedDot_GetResult_Request__Sequence * array)
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
      follow_msg__action__TrackRedDot_GetResult_Request__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_GetResult_Request__Sequence *
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Request__Sequence * array = (follow_msg__action__TrackRedDot_GetResult_Request__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__destroy(follow_msg__action__TrackRedDot_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__are_equal(const follow_msg__action__TrackRedDot_GetResult_Request__Sequence * lhs, const follow_msg__action__TrackRedDot_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_GetResult_Request__Sequence__copy(
  const follow_msg__action__TrackRedDot_GetResult_Request__Sequence * input,
  follow_msg__action__TrackRedDot_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_GetResult_Request * data =
      (follow_msg__action__TrackRedDot_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "follow_msg/action/detail/track_red_dot__functions.h"

bool
follow_msg__action__TrackRedDot_GetResult_Response__init(follow_msg__action__TrackRedDot_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!follow_msg__action__TrackRedDot_Result__init(&msg->result)) {
    follow_msg__action__TrackRedDot_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_GetResult_Response__fini(follow_msg__action__TrackRedDot_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  follow_msg__action__TrackRedDot_Result__fini(&msg->result);
}

bool
follow_msg__action__TrackRedDot_GetResult_Response__are_equal(const follow_msg__action__TrackRedDot_GetResult_Response * lhs, const follow_msg__action__TrackRedDot_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!follow_msg__action__TrackRedDot_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_GetResult_Response__copy(
  const follow_msg__action__TrackRedDot_GetResult_Response * input,
  follow_msg__action__TrackRedDot_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!follow_msg__action__TrackRedDot_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_GetResult_Response *
follow_msg__action__TrackRedDot_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Response * msg = (follow_msg__action__TrackRedDot_GetResult_Response *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_GetResult_Response));
  bool success = follow_msg__action__TrackRedDot_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_GetResult_Response__destroy(follow_msg__action__TrackRedDot_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__init(follow_msg__action__TrackRedDot_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Response * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_GetResult_Response *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_GetResult_Response__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__fini(follow_msg__action__TrackRedDot_GetResult_Response__Sequence * array)
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
      follow_msg__action__TrackRedDot_GetResult_Response__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_GetResult_Response__Sequence *
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_GetResult_Response__Sequence * array = (follow_msg__action__TrackRedDot_GetResult_Response__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__destroy(follow_msg__action__TrackRedDot_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__are_equal(const follow_msg__action__TrackRedDot_GetResult_Response__Sequence * lhs, const follow_msg__action__TrackRedDot_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_GetResult_Response__Sequence__copy(
  const follow_msg__action__TrackRedDot_GetResult_Response__Sequence * input,
  follow_msg__action__TrackRedDot_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_GetResult_Response * data =
      (follow_msg__action__TrackRedDot_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "follow_msg/action/detail/track_red_dot__functions.h"

bool
follow_msg__action__TrackRedDot_FeedbackMessage__init(follow_msg__action__TrackRedDot_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    follow_msg__action__TrackRedDot_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!follow_msg__action__TrackRedDot_Feedback__init(&msg->feedback)) {
    follow_msg__action__TrackRedDot_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
follow_msg__action__TrackRedDot_FeedbackMessage__fini(follow_msg__action__TrackRedDot_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  follow_msg__action__TrackRedDot_Feedback__fini(&msg->feedback);
}

bool
follow_msg__action__TrackRedDot_FeedbackMessage__are_equal(const follow_msg__action__TrackRedDot_FeedbackMessage * lhs, const follow_msg__action__TrackRedDot_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!follow_msg__action__TrackRedDot_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_FeedbackMessage__copy(
  const follow_msg__action__TrackRedDot_FeedbackMessage * input,
  follow_msg__action__TrackRedDot_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!follow_msg__action__TrackRedDot_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

follow_msg__action__TrackRedDot_FeedbackMessage *
follow_msg__action__TrackRedDot_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_FeedbackMessage * msg = (follow_msg__action__TrackRedDot_FeedbackMessage *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(follow_msg__action__TrackRedDot_FeedbackMessage));
  bool success = follow_msg__action__TrackRedDot_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
follow_msg__action__TrackRedDot_FeedbackMessage__destroy(follow_msg__action__TrackRedDot_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    follow_msg__action__TrackRedDot_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__init(follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_FeedbackMessage * data = NULL;

  if (size) {
    data = (follow_msg__action__TrackRedDot_FeedbackMessage *)allocator.zero_allocate(size, sizeof(follow_msg__action__TrackRedDot_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = follow_msg__action__TrackRedDot_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        follow_msg__action__TrackRedDot_FeedbackMessage__fini(&data[i - 1]);
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
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__fini(follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * array)
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
      follow_msg__action__TrackRedDot_FeedbackMessage__fini(&array->data[i]);
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

follow_msg__action__TrackRedDot_FeedbackMessage__Sequence *
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * array = (follow_msg__action__TrackRedDot_FeedbackMessage__Sequence *)allocator.allocate(sizeof(follow_msg__action__TrackRedDot_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__destroy(follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__are_equal(const follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * lhs, const follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!follow_msg__action__TrackRedDot_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
follow_msg__action__TrackRedDot_FeedbackMessage__Sequence__copy(
  const follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * input,
  follow_msg__action__TrackRedDot_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(follow_msg__action__TrackRedDot_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    follow_msg__action__TrackRedDot_FeedbackMessage * data =
      (follow_msg__action__TrackRedDot_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!follow_msg__action__TrackRedDot_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          follow_msg__action__TrackRedDot_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!follow_msg__action__TrackRedDot_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
