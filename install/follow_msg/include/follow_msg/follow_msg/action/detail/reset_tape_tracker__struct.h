// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from follow_msg:action/ResetTapeTracker.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__STRUCT_H_
#define FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_Goal
{
  uint8_t structure_needs_at_least_one_member;
} follow_msg__action__ResetTapeTracker_Goal;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_Goal.
typedef struct follow_msg__action__ResetTapeTracker_Goal__Sequence
{
  follow_msg__action__ResetTapeTracker_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_Result
{
  bool success;
  rosidl_runtime_c__String message;
} follow_msg__action__ResetTapeTracker_Result;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_Result.
typedef struct follow_msg__action__ResetTapeTracker_Result__Sequence
{
  follow_msg__action__ResetTapeTracker_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} follow_msg__action__ResetTapeTracker_Feedback;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_Feedback.
typedef struct follow_msg__action__ResetTapeTracker_Feedback__Sequence
{
  follow_msg__action__ResetTapeTracker_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "follow_msg/action/detail/reset_tape_tracker__struct.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  follow_msg__action__ResetTapeTracker_Goal goal;
} follow_msg__action__ResetTapeTracker_SendGoal_Request;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_SendGoal_Request.
typedef struct follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence
{
  follow_msg__action__ResetTapeTracker_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} follow_msg__action__ResetTapeTracker_SendGoal_Response;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_SendGoal_Response.
typedef struct follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence
{
  follow_msg__action__ResetTapeTracker_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} follow_msg__action__ResetTapeTracker_GetResult_Request;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_GetResult_Request.
typedef struct follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence
{
  follow_msg__action__ResetTapeTracker_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "follow_msg/action/detail/reset_tape_tracker__struct.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_GetResult_Response
{
  int8_t status;
  follow_msg__action__ResetTapeTracker_Result result;
} follow_msg__action__ResetTapeTracker_GetResult_Response;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_GetResult_Response.
typedef struct follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence
{
  follow_msg__action__ResetTapeTracker_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "follow_msg/action/detail/reset_tape_tracker__struct.h"

/// Struct defined in action/ResetTapeTracker in the package follow_msg.
typedef struct follow_msg__action__ResetTapeTracker_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  follow_msg__action__ResetTapeTracker_Feedback feedback;
} follow_msg__action__ResetTapeTracker_FeedbackMessage;

// Struct for a sequence of follow_msg__action__ResetTapeTracker_FeedbackMessage.
typedef struct follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence
{
  follow_msg__action__ResetTapeTracker_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__STRUCT_H_
