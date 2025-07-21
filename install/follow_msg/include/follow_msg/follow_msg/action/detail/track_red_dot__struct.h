// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from follow_msg:action/TrackRedDot.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_H_
#define FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_angles'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_Goal
{
  /// 路径点列表，x: yaw, y: pitch, z: unused
  geometry_msgs__msg__Point__Sequence target_angles;
  /// true: 相对, false: 绝对
  bool is_relative;
} follow_msg__action__TrackRedDot_Goal;

// Struct for a sequence of follow_msg__action__TrackRedDot_Goal.
typedef struct follow_msg__action__TrackRedDot_Goal__Sequence
{
  follow_msg__action__TrackRedDot_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_Result
{
  /// 动作执行结果
  bool success;
  /// 结果消息
  rosidl_runtime_c__String message;
} follow_msg__action__TrackRedDot_Result;

// Struct for a sequence of follow_msg__action__TrackRedDot_Result.
typedef struct follow_msg__action__TrackRedDot_Result__Sequence
{
  follow_msg__action__TrackRedDot_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} follow_msg__action__TrackRedDot_Feedback;

// Struct for a sequence of follow_msg__action__TrackRedDot_Feedback.
typedef struct follow_msg__action__TrackRedDot_Feedback__Sequence
{
  follow_msg__action__TrackRedDot_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "follow_msg/action/detail/track_red_dot__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  follow_msg__action__TrackRedDot_Goal goal;
} follow_msg__action__TrackRedDot_SendGoal_Request;

// Struct for a sequence of follow_msg__action__TrackRedDot_SendGoal_Request.
typedef struct follow_msg__action__TrackRedDot_SendGoal_Request__Sequence
{
  follow_msg__action__TrackRedDot_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} follow_msg__action__TrackRedDot_SendGoal_Response;

// Struct for a sequence of follow_msg__action__TrackRedDot_SendGoal_Response.
typedef struct follow_msg__action__TrackRedDot_SendGoal_Response__Sequence
{
  follow_msg__action__TrackRedDot_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} follow_msg__action__TrackRedDot_GetResult_Request;

// Struct for a sequence of follow_msg__action__TrackRedDot_GetResult_Request.
typedef struct follow_msg__action__TrackRedDot_GetResult_Request__Sequence
{
  follow_msg__action__TrackRedDot_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "follow_msg/action/detail/track_red_dot__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_GetResult_Response
{
  int8_t status;
  follow_msg__action__TrackRedDot_Result result;
} follow_msg__action__TrackRedDot_GetResult_Response;

// Struct for a sequence of follow_msg__action__TrackRedDot_GetResult_Response.
typedef struct follow_msg__action__TrackRedDot_GetResult_Response__Sequence
{
  follow_msg__action__TrackRedDot_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "follow_msg/action/detail/track_red_dot__struct.h"

/// Struct defined in action/TrackRedDot in the package follow_msg.
typedef struct follow_msg__action__TrackRedDot_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  follow_msg__action__TrackRedDot_Feedback feedback;
} follow_msg__action__TrackRedDot_FeedbackMessage;

// Struct for a sequence of follow_msg__action__TrackRedDot_FeedbackMessage.
typedef struct follow_msg__action__TrackRedDot_FeedbackMessage__Sequence
{
  follow_msg__action__TrackRedDot_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__TrackRedDot_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_H_
