// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_msg:msg/GraspMessage.idl
// generated code does not contain a copyright notice

#ifndef GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__TRAITS_HPP_
#define GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_msg/msg/detail/grasp_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'q_buf'
#include "grasp_msg/msg/detail/joint_pos__traits.hpp"

namespace grasp_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const GraspMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: q_buf
  {
    if (msg.q_buf.size() == 0) {
      out << "q_buf: []";
    } else {
      out << "q_buf: [";
      size_t pending_items = msg.q_buf.size();
      for (auto item : msg.q_buf) {
        to_flow_style_yaml(item, out);
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
  const GraspMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: q_buf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q_buf.size() == 0) {
      out << "q_buf: []\n";
    } else {
      out << "q_buf:\n";
      for (auto item : msg.q_buf) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GraspMessage & msg, bool use_flow_style = false)
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
  const grasp_msg::msg::GraspMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const grasp_msg::msg::GraspMessage & msg)
{
  return grasp_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_msg::msg::GraspMessage>()
{
  return "grasp_msg::msg::GraspMessage";
}

template<>
inline const char * name<grasp_msg::msg::GraspMessage>()
{
  return "grasp_msg/msg/GraspMessage";
}

template<>
struct has_fixed_size<grasp_msg::msg::GraspMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_msg::msg::GraspMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_msg::msg::GraspMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRASP_MSG__MSG__DETAIL__GRASP_MESSAGE__TRAITS_HPP_
