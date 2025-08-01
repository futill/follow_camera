// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "follow_msg/srv/detail/get_red_dot_position__rosidl_typesupport_introspection_c.h"
#include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "follow_msg/srv/detail/get_red_dot_position__functions.h"
#include "follow_msg/srv/detail/get_red_dot_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__srv__GetRedDotPosition_Request__init(message_memory);
}

void follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_fini_function(void * message_memory)
{
  follow_msg__srv__GetRedDotPosition_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__srv__GetRedDotPosition_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_members = {
  "follow_msg__srv",  // message namespace
  "GetRedDotPosition_Request",  // message name
  1,  // number of fields
  sizeof(follow_msg__srv__GetRedDotPosition_Request),
  follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_member_array,  // message members
  follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_type_support_handle = {
  0,
  &follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Request)() {
  if (!follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_type_support_handle.typesupport_identifier) {
    follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__srv__GetRedDotPosition_Request__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "follow_msg/srv/detail/get_red_dot_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "follow_msg/srv/detail/get_red_dot_position__functions.h"
// already included above
// #include "follow_msg/srv/detail/get_red_dot_position__struct.h"


// Include directives for member types
// Member `response`
#include "geometry_msgs/msg/point.h"
// Member `response`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  follow_msg__srv__GetRedDotPosition_Response__init(message_memory);
}

void follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_fini_function(void * message_memory)
{
  follow_msg__srv__GetRedDotPosition_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_member_array[1] = {
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(follow_msg__srv__GetRedDotPosition_Response, response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_members = {
  "follow_msg__srv",  // message namespace
  "GetRedDotPosition_Response",  // message name
  1,  // number of fields
  sizeof(follow_msg__srv__GetRedDotPosition_Response),
  follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_member_array,  // message members
  follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_type_support_handle = {
  0,
  &follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Response)() {
  follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_type_support_handle.typesupport_identifier) {
    follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &follow_msg__srv__GetRedDotPosition_Response__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "follow_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "follow_msg/srv/detail/get_red_dot_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_members = {
  "follow_msg__srv",  // service namespace
  "GetRedDotPosition",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_Request_message_type_support_handle,
  NULL  // response message
  // follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_Response_message_type_support_handle
};

static rosidl_service_type_support_t follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_type_support_handle = {
  0,
  &follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_follow_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition)() {
  if (!follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_type_support_handle.typesupport_identifier) {
    follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, follow_msg, srv, GetRedDotPosition_Response)()->data;
  }

  return &follow_msg__srv__detail__get_red_dot_position__rosidl_typesupport_introspection_c__GetRedDotPosition_service_type_support_handle;
}
