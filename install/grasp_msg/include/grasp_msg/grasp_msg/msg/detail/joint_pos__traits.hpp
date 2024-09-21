// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_msg:msg/JointPos.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__JOINT_POS__TRAITS_HPP_
#define GRASP_MSG__MSG__DETAIL__JOINT_POS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_msg/msg/detail/joint_pos__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace grasp_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointPos & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_pos
  {
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []";
    } else {
      out << "joint_pos: [";
      size_t pending_items = msg.joint_pos.size();
      for (auto item : msg.joint_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointPos & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []\n";
    } else {
      out << "joint_pos:\n";
      for (auto item : msg.joint_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointPos & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace grasp_msg

namespace rosidl_generator_traits
{

[[deprecated("use grasp_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_msg::msg::JointPos & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const grasp_msg::msg::JointPos & msg)
{
  return grasp_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_msg::msg::JointPos>()
{
  return "grasp_msg::msg::JointPos";
}

template<>
inline const char * name<grasp_msg::msg::JointPos>()
{
  return "grasp_msg/msg/JointPos";
}

template<>
struct has_fixed_size<grasp_msg::msg::JointPos>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<grasp_msg::msg::JointPos>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<grasp_msg::msg::JointPos>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRASP_MSG__MSG__DETAIL__JOINT_POS__TRAITS_HPP_
