// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from follow_msg:srv/GetRedDotPosition.idl
// generated code does not contain a copyright notice

#ifndef FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_HPP_
#define FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__follow_msg__srv__GetRedDotPosition_Request __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__srv__GetRedDotPosition_Request __declspec(deprecated)
#endif

namespace follow_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRedDotPosition_Request_
{
  using Type = GetRedDotPosition_Request_<ContainerAllocator>;

  explicit GetRedDotPosition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetRedDotPosition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__srv__GetRedDotPosition_Request
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__srv__GetRedDotPosition_Request
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRedDotPosition_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRedDotPosition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRedDotPosition_Request_

// alias to use template instance with default allocator
using GetRedDotPosition_Request =
  follow_msg::srv::GetRedDotPosition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace follow_msg


// Include directives for member types
// Member 'response'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__follow_msg__srv__GetRedDotPosition_Response __attribute__((deprecated))
#else
# define DEPRECATED__follow_msg__srv__GetRedDotPosition_Response __declspec(deprecated)
#endif

namespace follow_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRedDotPosition_Response_
{
  using Type = GetRedDotPosition_Response_<ContainerAllocator>;

  explicit GetRedDotPosition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_init)
  {
    (void)_init;
  }

  explicit GetRedDotPosition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _response_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__follow_msg__srv__GetRedDotPosition_Response
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__follow_msg__srv__GetRedDotPosition_Response
    std::shared_ptr<follow_msg::srv::GetRedDotPosition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRedDotPosition_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRedDotPosition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRedDotPosition_Response_

// alias to use template instance with default allocator
using GetRedDotPosition_Response =
  follow_msg::srv::GetRedDotPosition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace follow_msg

namespace follow_msg
{

namespace srv
{

struct GetRedDotPosition
{
  using Request = follow_msg::srv::GetRedDotPosition_Request;
  using Response = follow_msg::srv::GetRedDotPosition_Response;
};

}  // namespace srv

}  // namespace follow_msg

#endif  // FOLLOW_MSG__SRV__DETAIL__GET_RED_DOT_POSITION__STRUCT_HPP_
