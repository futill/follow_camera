// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__FUNCTIONS_H_
#define FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "follow_msg/msg/rosidl_generator_c__visibility_control.h"

#include "follow_msg/srv/detail/get_red_dot_position__struct.h"

/// Initialize srv/GetRedDotPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__srv__GetRedDotPosition_Request
 * )) before or use
 * follow_msg__srv__GetRedDotPosition_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__init(follow_msg__srv__GetRedDotPosition_Request * msg);

/// Finalize srv/GetRedDotPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Request__fini(follow_msg__srv__GetRedDotPosition_Request * msg);

/// Create srv/GetRedDotPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__srv__GetRedDotPosition_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__srv__GetRedDotPosition_Request *
follow_msg__srv__GetRedDotPosition_Request__create();

/// Destroy srv/GetRedDotPosition message.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Request__destroy(follow_msg__srv__GetRedDotPosition_Request * msg);

/// Check for srv/GetRedDotPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__are_equal(const follow_msg__srv__GetRedDotPosition_Request * lhs, const follow_msg__srv__GetRedDotPosition_Request * rhs);

/// Copy a srv/GetRedDotPosition message.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__copy(
  const follow_msg__srv__GetRedDotPosition_Request * input,
  follow_msg__srv__GetRedDotPosition_Request * output);

/// Initialize array of srv/GetRedDotPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__srv__GetRedDotPosition_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__init(follow_msg__srv__GetRedDotPosition_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetRedDotPosition messages.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Request__Sequence__fini(follow_msg__srv__GetRedDotPosition_Request__Sequence * array);

/// Create array of srv/GetRedDotPosition messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__srv__GetRedDotPosition_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__srv__GetRedDotPosition_Request__Sequence *
follow_msg__srv__GetRedDotPosition_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetRedDotPosition messages.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Request__Sequence__destroy(follow_msg__srv__GetRedDotPosition_Request__Sequence * array);

/// Check for srv/GetRedDotPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__are_equal(const follow_msg__srv__GetRedDotPosition_Request__Sequence * lhs, const follow_msg__srv__GetRedDotPosition_Request__Sequence * rhs);

/// Copy an array of srv/GetRedDotPosition messages.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Request__Sequence__copy(
  const follow_msg__srv__GetRedDotPosition_Request__Sequence * input,
  follow_msg__srv__GetRedDotPosition_Request__Sequence * output);

/// Initialize srv/GetRedDotPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__srv__GetRedDotPosition_Response
 * )) before or use
 * follow_msg__srv__GetRedDotPosition_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__init(follow_msg__srv__GetRedDotPosition_Response * msg);

/// Finalize srv/GetRedDotPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Response__fini(follow_msg__srv__GetRedDotPosition_Response * msg);

/// Create srv/GetRedDotPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__srv__GetRedDotPosition_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__srv__GetRedDotPosition_Response *
follow_msg__srv__GetRedDotPosition_Response__create();

/// Destroy srv/GetRedDotPosition message.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Response__destroy(follow_msg__srv__GetRedDotPosition_Response * msg);

/// Check for srv/GetRedDotPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__are_equal(const follow_msg__srv__GetRedDotPosition_Response * lhs, const follow_msg__srv__GetRedDotPosition_Response * rhs);

/// Copy a srv/GetRedDotPosition message.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__copy(
  const follow_msg__srv__GetRedDotPosition_Response * input,
  follow_msg__srv__GetRedDotPosition_Response * output);

/// Initialize array of srv/GetRedDotPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__srv__GetRedDotPosition_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__init(follow_msg__srv__GetRedDotPosition_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetRedDotPosition messages.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Response__Sequence__fini(follow_msg__srv__GetRedDotPosition_Response__Sequence * array);

/// Create array of srv/GetRedDotPosition messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__srv__GetRedDotPosition_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__srv__GetRedDotPosition_Response__Sequence *
follow_msg__srv__GetRedDotPosition_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetRedDotPosition messages.
/**
 * It calls
 * follow_msg__srv__GetRedDotPosition_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__srv__GetRedDotPosition_Response__Sequence__destroy(follow_msg__srv__GetRedDotPosition_Response__Sequence * array);

/// Check for srv/GetRedDotPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__are_equal(const follow_msg__srv__GetRedDotPosition_Response__Sequence * lhs, const follow_msg__srv__GetRedDotPosition_Response__Sequence * rhs);

/// Copy an array of srv/GetRedDotPosition messages.
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
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__srv__GetRedDotPosition_Response__Sequence__copy(
  const follow_msg__srv__GetRedDotPosition_Response__Sequence * input,
  follow_msg__srv__GetRedDotPosition_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__FUNCTIONS_H_
