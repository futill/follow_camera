// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__TRAITS_HPP_
#define FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "follow_msg/srv/detail/get_red_dot_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace follow_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRedDotPosition_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRedDotPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRedDotPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::srv::GetRedDotPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::srv::GetRedDotPosition_Request & msg)
{
  return follow_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::srv::GetRedDotPosition_Request>()
{
  return "follow_msg::srv::GetRedDotPosition_Request";
}

template<>
inline const char * name<follow_msg::srv::GetRedDotPosition_Request>()
{
  return "follow_msg/srv/GetRedDotPosition_Request";
}

template<>
struct has_fixed_size<follow_msg::srv::GetRedDotPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<follow_msg::srv::GetRedDotPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<follow_msg::srv::GetRedDotPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'response'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace follow_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRedDotPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    to_flow_style_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRedDotPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response:\n";
    to_block_style_yaml(msg.response, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRedDotPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace follow_msg

namespace rosidl_generator_traits
{

[[deprecated("use follow_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const follow_msg::srv::GetRedDotPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  follow_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use follow_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const follow_msg::srv::GetRedDotPosition_Response & msg)
{
  return follow_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<follow_msg::srv::GetRedDotPosition_Response>()
{
  return "follow_msg::srv::GetRedDotPosition_Response";
}

template<>
inline const char * name<follow_msg::srv::GetRedDotPosition_Response>()
{
  return "follow_msg/srv/GetRedDotPosition_Response";
}

template<>
struct has_fixed_size<follow_msg::srv::GetRedDotPosition_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<follow_msg::srv::GetRedDotPosition_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<follow_msg::srv::GetRedDotPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<follow_msg::srv::GetRedDotPosition>()
{
  return "follow_msg::srv::GetRedDotPosition";
}

template<>
inline const char * name<follow_msg::srv::GetRedDotPosition>()
{
  return "follow_msg/srv/GetRedDotPosition";
}

template<>
struct has_fixed_size<follow_msg::srv::GetRedDotPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<follow_msg::srv::GetRedDotPosition_Request>::value &&
    has_fixed_size<follow_msg::srv::GetRedDotPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<follow_msg::srv::GetRedDotPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<follow_msg::srv::GetRedDotPosition_Request>::value &&
    has_bounded_size<follow_msg::srv::GetRedDotPosition_Response>::value
  >
{
};

template<>
struct is_service<follow_msg::srv::GetRedDotPosition>
  : std::true_type
{
};

template<>
struct is_service_request<follow_msg::srv::GetRedDotPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<follow_msg::srv::GetRedDotPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__TRAITS_HPP_
