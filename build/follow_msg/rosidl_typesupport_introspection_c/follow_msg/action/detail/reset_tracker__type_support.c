// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from follow_msg:action/ResetTracker.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
#include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "follow_msg/action/detail/reset_tracker__functions.h"
#include "follow_msg/action/detail/reset_tracker__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_Goal__init(message_memory);
}

void follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_Goal, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_Goal",  // message name
  1,  // number of fields
  sizeof(follow_msg__action__ResetTracker_Goal),
  follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_member_array,  // message members
  follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Goal)() {
  if (!follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_Goal__rosidl_typesupport_introspection_c__ResetTracker_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_Result__init(message_memory);
}

void follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_Result",  // message name
  2,  // number of fields
  sizeof(follow_msg__action__ResetTracker_Result),
  follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_member_array,  // message members
  follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Result)() {
  if (!follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_Result__rosidl_typesupport_introspection_c__ResetTracker_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_Feedback__init(message_memory);
}

void follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_Feedback, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_Feedback",  // message name
  1,  // number of fields
  sizeof(follow_msg__action__ResetTracker_Feedback),
  follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_member_array,  // message members
  follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Feedback)() {
  if (!follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_Feedback__rosidl_typesupport_introspection_c__ResetTracker_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "follow_msg/action/reset_tracker.h"
// Member `goal`
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_SendGoal_Request__init(message_memory);
}

void follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(follow_msg__action__ResetTracker_SendGoal_Request),
  follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_member_array,  // message members
  follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Request)() {
  follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Goal)();
  if (!follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_SendGoal_Request__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_SendGoal_Response__init(message_memory);
}

void follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(follow_msg__action__ResetTracker_SendGoal_Response),
  follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_member_array,  // message members
  follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Response)() {
  follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_SendGoal_Response__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_members = {
  "follow_msg__action",  // service namespace
  "ResetTracker_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_type_support_handle = {
  0,
  &follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal)() {
  if (!follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_type_support_handle.typesupport_identifier) {
    follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_SendGoal_Response)()->data;
  }

  return &follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_GetResult_Request__init(message_memory);
}

void follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(follow_msg__action__ResetTracker_GetResult_Request),
  follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_member_array,  // message members
  follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Request)() {
  follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_GetResult_Request__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "follow_msg/action/reset_tracker.h"
// Member `result`
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_GetResult_Response__init(message_memory);
}

void follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(follow_msg__action__ResetTracker_GetResult_Response),
  follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_member_array,  // message members
  follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Response)() {
  follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Result)();
  if (!follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_GetResult_Response__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_members = {
  "follow_msg__action",  // service namespace
  "ResetTracker_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_type_support_handle = {
  0,
  &follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult)() {
  if (!follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_type_support_handle.typesupport_identifier) {
    follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_GetResult_Response)()->data;
  }

  return &follow_msg__action__detail__reset_tracker__rosidl_typesupport_introspection_c__ResetTracker_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__functions.h"
// already included above
// #include "follow_msg/action/detail/reset_tracker__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "follow_msg/action/reset_tracker.h"
// Member `feedback`
// already included above
// #include "follow_msg/action/detail/reset_tracker__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__action__ResetTracker_FeedbackMessage__init(message_memory);
}

void follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_fini_function(void * message_memory)
{
  follow_msg__action__ResetTracker_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__action__ResetTracker_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_members = {
  "follow_msg__action",  // message namespace
  "ResetTracker_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(follow_msg__action__ResetTracker_FeedbackMessage),
  follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_member_array,  // message members
  follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_type_support_handle = {
  0,
  &follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_FeedbackMessage)() {
  follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, action, ResetTracker_Feedback)();
  if (!follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__action__ResetTracker_FeedbackMessage__rosidl_typesupport_introspection_c__ResetTracker_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
