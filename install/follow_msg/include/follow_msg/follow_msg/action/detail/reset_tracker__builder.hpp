// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from follow_msg:action/ResetTracker.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__RESET_TRACKER__BUILDER_HPP_
#define FOLLOW_MSG__ACTION__DETAIL__RESET_TRACKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "follow_msg/action/detail/reset_tracker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace follow_msg
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_Goal>()
{
  return ::follow_msg::action::ResetTracker_Goal(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_Result_message
{
public:
  explicit Init_ResetTracker_Result_message(::follow_msg::action::ResetTracker_Result & msg)
  : msg_(msg)
  {}
  ::follow_msg::action::ResetTracker_Result message(::follow_msg::action::ResetTracker_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_Result msg_;
};

class Init_ResetTracker_Result_success
{
public:
  Init_ResetTracker_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetTracker_Result_message success(::follow_msg::action::ResetTracker_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ResetTracker_Result_message(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_Result>()
{
  return follow_msg::action::builder::Init_ResetTracker_Result_success();
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_Feedback>()
{
  return ::follow_msg::action::ResetTracker_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_SendGoal_Request_goal
{
public:
  explicit Init_ResetTracker_SendGoal_Request_goal(::follow_msg::action::ResetTracker_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::follow_msg::action::ResetTracker_SendGoal_Request goal(::follow_msg::action::ResetTracker_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_SendGoal_Request msg_;
};

class Init_ResetTracker_SendGoal_Request_goal_id
{
public:
  Init_ResetTracker_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetTracker_SendGoal_Request_goal goal_id(::follow_msg::action::ResetTracker_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ResetTracker_SendGoal_Request_goal(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_SendGoal_Request>()
{
  return follow_msg::action::builder::Init_ResetTracker_SendGoal_Request_goal_id();
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_SendGoal_Response_stamp
{
public:
  explicit Init_ResetTracker_SendGoal_Response_stamp(::follow_msg::action::ResetTracker_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::follow_msg::action::ResetTracker_SendGoal_Response stamp(::follow_msg::action::ResetTracker_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_SendGoal_Response msg_;
};

class Init_ResetTracker_SendGoal_Response_accepted
{
public:
  Init_ResetTracker_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetTracker_SendGoal_Response_stamp accepted(::follow_msg::action::ResetTracker_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ResetTracker_SendGoal_Response_stamp(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_SendGoal_Response>()
{
  return follow_msg::action::builder::Init_ResetTracker_SendGoal_Response_accepted();
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_GetResult_Request_goal_id
{
public:
  Init_ResetTracker_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::follow_msg::action::ResetTracker_GetResult_Request goal_id(::follow_msg::action::ResetTracker_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_GetResult_Request>()
{
  return follow_msg::action::builder::Init_ResetTracker_GetResult_Request_goal_id();
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_GetResult_Response_result
{
public:
  explicit Init_ResetTracker_GetResult_Response_result(::follow_msg::action::ResetTracker_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::follow_msg::action::ResetTracker_GetResult_Response result(::follow_msg::action::ResetTracker_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_GetResult_Response msg_;
};

class Init_ResetTracker_GetResult_Response_status
{
public:
  Init_ResetTracker_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetTracker_GetResult_Response_result status(::follow_msg::action::ResetTracker_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ResetTracker_GetResult_Response_result(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_GetResult_Response>()
{
  return follow_msg::action::builder::Init_ResetTracker_GetResult_Response_status();
}

}  // namespace follow_msg


namespace follow_msg
{

namespace action
{

namespace builder
{

class Init_ResetTracker_FeedbackMessage_feedback
{
public:
  explicit Init_ResetTracker_FeedbackMessage_feedback(::follow_msg::action::ResetTracker_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::follow_msg::action::ResetTracker_FeedbackMessage feedback(::follow_msg::action::ResetTracker_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_FeedbackMessage msg_;
};

class Init_ResetTracker_FeedbackMessage_goal_id
{
public:
  Init_ResetTracker_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetTracker_FeedbackMessage_feedback goal_id(::follow_msg::action::ResetTracker_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ResetTracker_FeedbackMessage_feedback(msg_);
  }

private:
  ::follow_msg::action::ResetTracker_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::follow_msg::action::ResetTracker_FeedbackMessage>()
{
  return follow_msg::action::builder::Init_ResetTracker_FeedbackMessage_goal_id();
}

}  // namespace follow_msg

#endif  // FOLLOW_MSG__ACTION__DETAIL__RESET_TRACKER__BUILDER_HPP_
