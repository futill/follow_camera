// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from follow_msg:action/TrackRedDot.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__TRAITS_HPP_
#define FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "follow_msg/action/detail/track_red_dot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_angles'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_angles
  {
    if (msg.target_angles.size() == 0) {
      out << "target_angles: []";
    } else {
      out << "target_angles: [";
      size_t pending_items = msg.target_angles.size();
      for (auto item : msg.target_angles) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_relative
  {
    out << "is_relative: ";
    rosidl_generator_traits::value_to_yaml(msg.is_relative, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_angles.size() == 0) {
      out << "target_angles: []\n";
    } else {
      out << "target_angles:\n";
      for (auto item : msg.target_angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: is_relative
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_relative: ";
    rosidl_generator_traits::value_to_yaml(msg.is_relative, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_Goal & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_Goal>()
{
  return "follow_msg::action::TrackRedDot_Goal";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_Goal>()
{
  return "follow_msg/action/TrackRedDot_Goal";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_Result & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_Result>()
{
  return "follow_msg::action::TrackRedDot_Result";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_Result>()
{
  return "follow_msg/action/TrackRedDot_Result";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_Feedback & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_Feedback & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_Feedback>()
{
  return "follow_msg::action::TrackRedDot_Feedback";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_Feedback>()
{
  return "follow_msg/action/TrackRedDot_Feedback";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "follow_msg/action/detail/track_red_dot__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_SendGoal_Request & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_SendGoal_Request>()
{
  return "follow_msg::action::TrackRedDot_SendGoal_Request";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_SendGoal_Request>()
{
  return "follow_msg/action/TrackRedDot_SendGoal_Request";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<follow_msg::action::TrackRedDot_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<follow_msg::action::TrackRedDot_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_SendGoal_Response & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_SendGoal_Response>()
{
  return "follow_msg::action::TrackRedDot_SendGoal_Response";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_SendGoal_Response>()
{
  return "follow_msg/action/TrackRedDot_SendGoal_Response";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_SendGoal>()
{
  return "follow_msg::action::TrackRedDot_SendGoal";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_SendGoal>()
{
  return "follow_msg/action/TrackRedDot_SendGoal";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<follow_msg::action::TrackRedDot_SendGoal_Request>::value &&
    has_fixed_size<follow_msg::action::TrackRedDot_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<follow_msg::action::TrackRedDot_SendGoal_Request>::value &&
    has_bounded_size<follow_msg::action::TrackRedDot_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<follow_msg::action::TrackRedDot_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<follow_msg::action::TrackRedDot_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<follow_msg::action::TrackRedDot_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_GetResult_Request & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_GetResult_Request>()
{
  return "follow_msg::action::TrackRedDot_GetResult_Request";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_GetResult_Request>()
{
  return "follow_msg/action/TrackRedDot_GetResult_Request";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "follow_msg/action/detail/track_red_dot__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_GetResult_Response & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_GetResult_Response>()
{
  return "follow_msg::action::TrackRedDot_GetResult_Response";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_GetResult_Response>()
{
  return "follow_msg/action/TrackRedDot_GetResult_Response";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<follow_msg::action::TrackRedDot_Result>::value> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<follow_msg::action::TrackRedDot_Result>::value> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_GetResult>()
{
  return "follow_msg::action::TrackRedDot_GetResult";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_GetResult>()
{
  return "follow_msg/action/TrackRedDot_GetResult";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<follow_msg::action::TrackRedDot_GetResult_Request>::value &&
    has_fixed_size<follow_msg::action::TrackRedDot_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<follow_msg::action::TrackRedDot_GetResult_Request>::value &&
    has_bounded_size<follow_msg::action::TrackRedDot_GetResult_Response>::value
  >
{
};

template<>
struct is_service<follow_msg::action::TrackRedDot_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<follow_msg::action::TrackRedDot_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<follow_msg::action::TrackRedDot_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "follow_msg/action/detail/track_red_dot__traits.hpp"

namespace follow_msg
{

namespace action
{

inline void to_flow_style_yaml(
  const TrackRedDot_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackRedDot_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackRedDot_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::action::TrackRedDot_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::action::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::action::TrackRedDot_FeedbackMessage & msg)
{
  return follow_msg::action::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::action::TrackRedDot_FeedbackMessage>()
{
  return "follow_msg::action::TrackRedDot_FeedbackMessage";
}

template<>
inline const char * name<follow_msg::action::TrackRedDot_FeedbackMessage>()
{
  return "follow_msg/action/TrackRedDot_FeedbackMessage";
}

template<>
struct has_fixed_size<follow_msg::action::TrackRedDot_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<follow_msg::action::TrackRedDot_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<follow_msg::action::TrackRedDot_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<follow_msg::action::TrackRedDot_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<follow_msg::action::TrackRedDot_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<follow_msg::action::TrackRedDot>
  : std::true_type
{
};

template<>
struct is_action_goal<follow_msg::action::TrackRedDot_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<follow_msg::action::TrackRedDot_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<follow_msg::action::TrackRedDot_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__TRAITS_HPP_
