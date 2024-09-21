// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_HPP_
#define GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'q_buf'
#include "grasp_msg/msg/detail/joint_pos__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__grasp_msg__msg__GraspMessage __attribute__((deprecated))
#else
# define DEPRECATED__grasp_msg__msg__GraspMessage __declspec(deprecated)
#endif

namespace grasp_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GraspMessage_
{
  using Type = GraspMessage_<ContainerAllocator>;

  explicit GraspMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GraspMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _q_buf_type =
    std::vector<grasp_msg::msg::JointPos_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<grasp_msg::msg::JointPos_<ContainerAllocator>>>;
  _q_buf_type q_buf;

  // setters for named parameter idiom
  Type & set__q_buf(
    const std::vector<grasp_msg::msg::JointPos_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<grasp_msg::msg::JointPos_<ContainerAllocator>>> & _arg)
  {
    this->q_buf = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_msg::msg::GraspMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_msg::msg::GraspMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_msg::msg::GraspMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_msg::msg::GraspMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_msg__msg__GraspMessage
    std::shared_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_msg__msg__GraspMessage
    std::shared_ptr<grasp_msg::msg::GraspMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GraspMessage_ & other) const
  {
    if (this->q_buf != other.q_buf) {
      return false;
    }
    return true;
  }
  bool operator!=(const GraspMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GraspMessage_

// alias to use template instance with default allocator
using GraspMessage =
  grasp_msg::msg::GraspMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace grasp_msg

#endif  // GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__STRUCT_HPP_
