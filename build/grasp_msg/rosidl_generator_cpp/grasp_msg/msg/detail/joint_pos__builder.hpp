// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__JOINT_POS__BUILDER_HPP_
#define GRASP_MSG__MSG__DETAIL__JOINT_POS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_msg/msg/detail/joint_pos__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_msg
{

namespace msg
{

namespace builder
{

class Init_JointPos_joint_pos
{
public:
  Init_JointPos_joint_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::grasp_msg::msg::JointPos joint_pos(::grasp_msg::msg::JointPos::_joint_pos_type arg)
  {
    msg_.joint_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_msg::msg::JointPos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_msg::msg::JointPos>()
{
  return grasp_msg::msg::builder::Init_JointPos_joint_pos();
}

}  // namespace grasp_msg

#endif  // GRASP_MSG__MSG__DETAIL__JOINT_POS__BUILDER_HPP_
