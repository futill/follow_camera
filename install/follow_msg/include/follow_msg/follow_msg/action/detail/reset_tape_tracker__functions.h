// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from follow_msg:action/ResetTapeTracker.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__FUNCTIONS_H_
#define FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "follow_msg/msg/rosidl_generator_c__visibility_control.h"

#include "follow_msg/action/detail/reset_tape_tracker__struct.h"

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_Goal
 * )) before or use
 * follow_msg__action__ResetTapeTracker_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Goal__init(follow_msg__action__ResetTapeTracker_Goal * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Goal__fini(follow_msg__action__ResetTapeTracker_Goal * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Goal *
follow_msg__action__ResetTapeTracker_Goal__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Goal__destroy(follow_msg__action__ResetTapeTracker_Goal * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Goal__are_equal(const follow_msg__action__ResetTapeTracker_Goal * lhs, const follow_msg__action__ResetTapeTracker_Goal * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_Goal__copy(
  const follow_msg__action__ResetTapeTracker_Goal * input,
  follow_msg__action__ResetTapeTracker_Goal * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Goal__Sequence__init(follow_msg__action__ResetTapeTracker_Goal__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Goal__Sequence__fini(follow_msg__action__ResetTapeTracker_Goal__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Goal__Sequence *
follow_msg__action__ResetTapeTracker_Goal__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Goal__Sequence__destroy(follow_msg__action__ResetTapeTracker_Goal__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Goal__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_Goal__Sequence * lhs, const follow_msg__action__ResetTapeTracker_Goal__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_Goal__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_Goal__Sequence * input,
  follow_msg__action__ResetTapeTracker_Goal__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_Result
 * )) before or use
 * follow_msg__action__ResetTapeTracker_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Result__init(follow_msg__action__ResetTapeTracker_Result * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Result__fini(follow_msg__action__ResetTapeTracker_Result * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Result *
follow_msg__action__ResetTapeTracker_Result__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Result__destroy(follow_msg__action__ResetTapeTracker_Result * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Result__are_equal(const follow_msg__action__ResetTapeTracker_Result * lhs, const follow_msg__action__ResetTapeTracker_Result * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_Result__copy(
  const follow_msg__action__ResetTapeTracker_Result * input,
  follow_msg__action__ResetTapeTracker_Result * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Result__Sequence__init(follow_msg__action__ResetTapeTracker_Result__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Result__Sequence__fini(follow_msg__action__ResetTapeTracker_Result__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Result__Sequence *
follow_msg__action__ResetTapeTracker_Result__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Result__Sequence__destroy(follow_msg__action__ResetTapeTracker_Result__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Result__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_Result__Sequence * lhs, const follow_msg__action__ResetTapeTracker_Result__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_Result__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_Result__Sequence * input,
  follow_msg__action__ResetTapeTracker_Result__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_Feedback
 * )) before or use
 * follow_msg__action__ResetTapeTracker_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Feedback__init(follow_msg__action__ResetTapeTracker_Feedback * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Feedback__fini(follow_msg__action__ResetTapeTracker_Feedback * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Feedback *
follow_msg__action__ResetTapeTracker_Feedback__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Feedback__destroy(follow_msg__action__ResetTapeTracker_Feedback * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Feedback__are_equal(const follow_msg__action__ResetTapeTracker_Feedback * lhs, const follow_msg__action__ResetTapeTracker_Feedback * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_Feedback__copy(
  const follow_msg__action__ResetTapeTracker_Feedback * input,
  follow_msg__action__ResetTapeTracker_Feedback * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Feedback__Sequence__init(follow_msg__action__ResetTapeTracker_Feedback__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Feedback__Sequence__fini(follow_msg__action__ResetTapeTracker_Feedback__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_Feedback__Sequence *
follow_msg__action__ResetTapeTracker_Feedback__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_Feedback__Sequence__destroy(follow_msg__action__ResetTapeTracker_Feedback__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_Feedback__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_Feedback__Sequence * lhs, const follow_msg__action__ResetTapeTracker_Feedback__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_Feedback__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_Feedback__Sequence * input,
  follow_msg__action__ResetTapeTracker_Feedback__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_SendGoal_Request
 * )) before or use
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Request__init(follow_msg__action__ResetTapeTracker_SendGoal_Request * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Request__fini(follow_msg__action__ResetTapeTracker_SendGoal_Request * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_SendGoal_Request *
follow_msg__action__ResetTapeTracker_SendGoal_Request__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Request__destroy(follow_msg__action__ResetTapeTracker_SendGoal_Request * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Request__are_equal(const follow_msg__action__ResetTapeTracker_SendGoal_Request * lhs, const follow_msg__action__ResetTapeTracker_SendGoal_Request * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_SendGoal_Request__copy(
  const follow_msg__action__ResetTapeTracker_SendGoal_Request * input,
  follow_msg__action__ResetTapeTracker_SendGoal_Request * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__init(follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__fini(follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence *
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__destroy(follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * lhs, const follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * input,
  follow_msg__action__ResetTapeTracker_SendGoal_Request__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_SendGoal_Response
 * )) before or use
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Response__init(follow_msg__action__ResetTapeTracker_SendGoal_Response * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Response__fini(follow_msg__action__ResetTapeTracker_SendGoal_Response * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_SendGoal_Response *
follow_msg__action__ResetTapeTracker_SendGoal_Response__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Response__destroy(follow_msg__action__ResetTapeTracker_SendGoal_Response * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Response__are_equal(const follow_msg__action__ResetTapeTracker_SendGoal_Response * lhs, const follow_msg__action__ResetTapeTracker_SendGoal_Response * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_SendGoal_Response__copy(
  const follow_msg__action__ResetTapeTracker_SendGoal_Response * input,
  follow_msg__action__ResetTapeTracker_SendGoal_Response * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__init(follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__fini(follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence *
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__destroy(follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * lhs, const follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * input,
  follow_msg__action__ResetTapeTracker_SendGoal_Response__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_GetResult_Request
 * )) before or use
 * follow_msg__action__ResetTapeTracker_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Request__init(follow_msg__action__ResetTapeTracker_GetResult_Request * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Request__fini(follow_msg__action__ResetTapeTracker_GetResult_Request * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_GetResult_Request *
follow_msg__action__ResetTapeTracker_GetResult_Request__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Request__destroy(follow_msg__action__ResetTapeTracker_GetResult_Request * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Request__are_equal(const follow_msg__action__ResetTapeTracker_GetResult_Request * lhs, const follow_msg__action__ResetTapeTracker_GetResult_Request * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_GetResult_Request__copy(
  const follow_msg__action__ResetTapeTracker_GetResult_Request * input,
  follow_msg__action__ResetTapeTracker_GetResult_Request * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__init(follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__fini(follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence *
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__destroy(follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * lhs, const follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * input,
  follow_msg__action__ResetTapeTracker_GetResult_Request__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_GetResult_Response
 * )) before or use
 * follow_msg__action__ResetTapeTracker_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Response__init(follow_msg__action__ResetTapeTracker_GetResult_Response * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Response__fini(follow_msg__action__ResetTapeTracker_GetResult_Response * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_GetResult_Response *
follow_msg__action__ResetTapeTracker_GetResult_Response__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Response__destroy(follow_msg__action__ResetTapeTracker_GetResult_Response * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Response__are_equal(const follow_msg__action__ResetTapeTracker_GetResult_Response * lhs, const follow_msg__action__ResetTapeTracker_GetResult_Response * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_GetResult_Response__copy(
  const follow_msg__action__ResetTapeTracker_GetResult_Response * input,
  follow_msg__action__ResetTapeTracker_GetResult_Response * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__init(follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__fini(follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence *
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__destroy(follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * lhs, const follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * input,
  follow_msg__action__ResetTapeTracker_GetResult_Response__Sequence * output);

/// Initialize action/ResetTapeTracker message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * follow_msg__action__ResetTapeTracker_FeedbackMessage
 * )) before or use
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_FeedbackMessage__init(follow_msg__action__ResetTapeTracker_FeedbackMessage * msg);

/// Finalize action/ResetTapeTracker message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_FeedbackMessage__fini(follow_msg__action__ResetTapeTracker_FeedbackMessage * msg);

/// Create action/ResetTapeTracker message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_FeedbackMessage *
follow_msg__action__ResetTapeTracker_FeedbackMessage__create();

/// Destroy action/ResetTapeTracker message.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_FeedbackMessage__destroy(follow_msg__action__ResetTapeTracker_FeedbackMessage * msg);

/// Check for action/ResetTapeTracker message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_FeedbackMessage__are_equal(const follow_msg__action__ResetTapeTracker_FeedbackMessage * lhs, const follow_msg__action__ResetTapeTracker_FeedbackMessage * rhs);

/// Copy a action/ResetTapeTracker message.
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
follow_msg__action__ResetTapeTracker_FeedbackMessage__copy(
  const follow_msg__action__ResetTapeTracker_FeedbackMessage * input,
  follow_msg__action__ResetTapeTracker_FeedbackMessage * output);

/// Initialize array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the number of elements and calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__init(follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__fini(follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * array);

/// Create array of action/ResetTapeTracker messages.
/**
 * It allocates the memory for the array and calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence *
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/ResetTapeTracker messages.
/**
 * It calls
 * follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
void
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__destroy(follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * array);

/// Check for action/ResetTapeTracker message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_follow_msg
bool
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__are_equal(const follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * lhs, const follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/ResetTapeTracker messages.
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
follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence__copy(
  const follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * input,
  follow_msg__action__ResetTapeTracker_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FOLLOW_MSG__ACTION__DETAIL__RESET_TAPE_TRACKER__FUNCTIONS_H_
