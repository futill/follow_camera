// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__BUILDER_HPP_
#define FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "follow_msg/srv/detail/get_red_dot_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace follow_msg
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::srv::GetRedDotPosition_Request>()
{
  return ::follow_msg::srv::GetRedDotPosition_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace follow_msg


namespace follow_msg
{

namespace srv
{

namespace builder
{

class Init_GetRedDotPosition_Response_response
{
public:
  Init_GetRedDotPosition_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::follow_msg::srv::GetRedDotPosition_Response response(::follow_msg::srv::GetRedDotPosition_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::srv::GetRedDotPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::srv::GetRedDotPosition_Response>()
{
  return follow_msg::srv::builder::Init_GetRedDotPosition_Response_response();
}

}  // namespace follow_msg

#endif  // FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__BUILDER_HPP_
