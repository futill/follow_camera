// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from follow_msg:action/TrackRedDot.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_HPP_
#define FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_angles'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_Goal __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_Goal __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_Goal_
{
  using Type = TrackRedDot_Goal_<ContainerAllocator>;

  explicit TrackRedDot_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_relative = false;
    }
  }

  explicit TrackRedDot_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_relative = false;
    }
  }

  // field types and members
  using _target_angles_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _target_angles_type target_angles;
  using _is_relative_type =
    bool;
  _is_relative_type is_relative;

  // setters for named parameter idiom
  Type & set__target_angles(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->target_angles = _arg;
    return *this;
  }
  Type & set__is_relative(
    const bool & _arg)
  {
    this->is_relative = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Goal
    std::shared_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Goal
    std::shared_ptr<follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_Goal_ & other) const
  {
    if (this->target_angles != other.target_angles) {
      return false;
    }
    if (this->is_relative != other.is_relative) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_Goal_

// alias to use template instance with default allocator
using TrackRedDot_Goal =
  follow_msg::action::TrackRedDot_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg


#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_Result __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_Result __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_Result_
{
  using Type = TrackRedDot_Result_<ContainerAllocator>;

  explicit TrackRedDot_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit TrackRedDot_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Result
    std::shared_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Result
    std::shared_ptr<follow_msg::action::TrackRedDot_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_Result_

// alias to use template instance with default allocator
using TrackRedDot_Result =
  follow_msg::action::TrackRedDot_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg


#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_Feedback __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_Feedback_
{
  using Type = TrackRedDot_Feedback_<ContainerAllocator>;

  explicit TrackRedDot_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit TrackRedDot_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Feedback
    std::shared_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_Feedback
    std::shared_ptr<follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_Feedback_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_Feedback_

// alias to use template instance with default allocator
using TrackRedDot_Feedback =
  follow_msg::action::TrackRedDot_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "follow_msg/action/detail/track_red_dot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Request __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_SendGoal_Request_
{
  using Type = TrackRedDot_SendGoal_Request_<ContainerAllocator>;

  explicit TrackRedDot_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit TrackRedDot_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    follow_msg::action::TrackRedDot_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const follow_msg::action::TrackRedDot_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Request
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Request
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_SendGoal_Request_

// alias to use template instance with default allocator
using TrackRedDot_SendGoal_Request =
  follow_msg::action::TrackRedDot_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Response __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_SendGoal_Response_
{
  using Type = TrackRedDot_SendGoal_Response_<ContainerAllocator>;

  explicit TrackRedDot_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit TrackRedDot_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Response
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_SendGoal_Response
    std::shared_ptr<follow_msg::action::TrackRedDot_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_SendGoal_Response_

// alias to use template instance with default allocator
using TrackRedDot_SendGoal_Response =
  follow_msg::action::TrackRedDot_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg

namespace follow_msg
{

namespace action
{

struct TrackRedDot_SendGoal
{
  using Request = follow_msg::action::TrackRedDot_SendGoal_Request;
  using Response = follow_msg::action::TrackRedDot_SendGoal_Response;
};

}  // namespace action

}  // namespace follow_msg


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Request __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_GetResult_Request_
{
  using Type = TrackRedDot_GetResult_Request_<ContainerAllocator>;

  explicit TrackRedDot_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit TrackRedDot_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Request
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Request
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_GetResult_Request_

// alias to use template instance with default allocator
using TrackRedDot_GetResult_Request =
  follow_msg::action::TrackRedDot_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg


// Include directives for member types
// Member 'result'
// already included above
// #include "follow_msg/action/detail/track_red_dot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Response __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_GetResult_Response_
{
  using Type = TrackRedDot_GetResult_Response_<ContainerAllocator>;

  explicit TrackRedDot_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit TrackRedDot_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    follow_msg::action::TrackRedDot_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const follow_msg::action::TrackRedDot_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Response
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_GetResult_Response
    std::shared_ptr<follow_msg::action::TrackRedDot_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_GetResult_Response_

// alias to use template instance with default allocator
using TrackRedDot_GetResult_Response =
  follow_msg::action::TrackRedDot_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg

namespace follow_msg
{

namespace action
{

struct TrackRedDot_GetResult
{
  using Request = follow_msg::action::TrackRedDot_GetResult_Request;
  using Response = follow_msg::action::TrackRedDot_GetResult_Response;
};

}  // namespace action

}  // namespace follow_msg


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "follow_msg/action/detail/track_red_dot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__action__TrackRedDot_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__action__TrackRedDot_FeedbackMessage __declspec(deprecated)
#endif

namespace follow_msg
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrackRedDot_FeedbackMessage_
{
  using Type = TrackRedDot_FeedbackMessage_<ContainerAllocator>;

  explicit TrackRedDot_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit TrackRedDot_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const follow_msg::action::TrackRedDot_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__action__TrackRedDot_FeedbackMessage
    std::shared_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__action__TrackRedDot_FeedbackMessage
    std::shared_ptr<follow_msg::action::TrackRedDot_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackRedDot_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackRedDot_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackRedDot_FeedbackMessage_

// alias to use template instance with default allocator
using TrackRedDot_FeedbackMessage =
  follow_msg::action::TrackRedDot_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace follow_msg

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace follow_msg
{

namespace action
{

struct TrackRedDot
{
  /// The goal message defined in the action definition.
  using Goal = follow_msg::action::TrackRedDot_Goal;
  /// The result message defined in the action definition.
  using Result = follow_msg::action::TrackRedDot_Result;
  /// The feedback message defined in the action definition.
  using Feedback = follow_msg::action::TrackRedDot_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = follow_msg::action::TrackRedDot_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = follow_msg::action::TrackRedDot_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = follow_msg::action::TrackRedDot_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct TrackRedDot TrackRedDot;

}  // namespace action

}  // namespace follow_msg

#endif  // FOLLOW_MSG__ACTION__DETAIL__TRACK_RED_DOT__STRUCT_HPP_
