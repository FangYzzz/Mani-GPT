// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__BUILDER_HPP_
#define GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_msg/msg/detail/grasp_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_msg
{

namespace msg
{

namespace builder
{

class Init_GraspMessage_q_buf
{
public:
  Init_GraspMessage_q_buf()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::grasp_msg::msg::GraspMessage q_buf(::grasp_msg::msg::GraspMessage::_q_buf_type arg)
  {
    msg_.q_buf = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_msg::msg::GraspMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_msg::msg::GraspMessage>()
{
  return grasp_msg::msg::builder::Init_GraspMessage_q_buf();
}

}  // namespace grasp_msg

#endif  // GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__BUILDER_HPP_
