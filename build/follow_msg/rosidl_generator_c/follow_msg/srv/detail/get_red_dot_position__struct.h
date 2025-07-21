// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_H_
#define FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRedDotPosition in the package follow_msg.
typedef struct follow_msg__srv__GetRedDotPosition_Request
{
  uint8_t structure_needs_at_least_one_member;
} follow_msg__srv__GetRedDotPosition_Request;

// Struct for a sequence of follow_msg__srv__GetRedDotPosition_Request.
typedef struct follow_msg__srv__GetRedDotPosition_Request__Sequence
{
  follow_msg__srv__GetRedDotPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__srv__GetRedDotPosition_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/GetRedDotPosition in the package follow_msg.
typedef struct follow_msg__srv__GetRedDotPosition_Response
{
  geometry_msgs__msg__Point response;
} follow_msg__srv__GetRedDotPosition_Response;

// Struct for a sequence of follow_msg__srv__GetRedDotPosition_Response.
typedef struct follow_msg__srv__GetRedDotPosition_Response__Sequence
{
  follow_msg__srv__GetRedDotPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__srv__GetRedDotPosition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_H_
