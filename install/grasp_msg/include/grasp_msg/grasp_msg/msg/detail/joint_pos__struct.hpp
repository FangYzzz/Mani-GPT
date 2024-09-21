// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_HPP_
#define GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__grasp_msg__msg__JointPos __attribute__((deprecated))
#else
# define DEPRECATED__grasp_msg__msg__JointPos __declspec(deprecated)
#endif

namespace grasp_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointPos_
{
  using Type = JointPos_<ContainerAllocator>;

  explicit JointPos_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->joint_pos.begin(), this->joint_pos.end(), 0.0);
    }
  }

  explicit JointPos_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_pos(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->joint_pos.begin(), this->joint_pos.end(), 0.0);
    }
  }

  // field types and members
  using _joint_pos_type =
    std::array<double, 7>;
  _joint_pos_type joint_pos;

  // setters for named parameter idiom
  Type & set__joint_pos(
    const std::array<double, 7> & _arg)
  {
    this->joint_pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_msg::msg::JointPos_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_msg::msg::JointPos_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_msg::msg::JointPos_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_msg::msg::JointPos_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_msg::msg::JointPos_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_msg::msg::JointPos_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_msg::msg::JointPos_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_msg::msg::JointPos_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_msg::msg::JointPos_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_msg::msg::JointPos_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_msg__msg__JointPos
    std::shared_ptr<grasp_msg::msg::JointPos_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_msg__msg__JointPos
    std::shared_ptr<grasp_msg::msg::JointPos_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointPos_ & other) const
  {
    if (this->joint_pos != other.joint_pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointPos_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointPos_

// alias to use template instance with default allocator
using JointPos =
  grasp_msg::msg::JointPos_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace grasp_msg

#endif  // GRASP_MSG__MSG__DETAIL__JOINT_POS__STRUCT_HPP_
