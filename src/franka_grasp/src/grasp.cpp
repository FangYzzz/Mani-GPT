#include <cmath>
#include <iostream>
#include <franka/exception.h>
#include <franka/robot.h>
#include <franka/gripper.h>
#include <rclcpp/rclcpp.hpp>
#include <eigen3/Eigen/Eigen>
#include "examples_common.h"
#include "grasp_msg/msg/grasp_message.hpp"
class GraspSubscriber : public rclcpp::Node
{
  public:
    GraspSubscriber()
    : Node("grasp_subscriber")
    {
      subscription_ = this->create_subscription<grasp_msg::msg::GraspMessage>(
      "grasp_position", 10, std::bind(&GraspSubscriber::topic_callback, this, std::placeholders::_1));
      std::array<double, 7> q_buf = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
      // grasp(q_buf);
    }
    int grasp(std::array<double, 7> q_buf) {
      // std::cerr << "grasps position:\n" << translation{};

      try {
        franka::Robot robot("192.168.2.55");
        franka::Gripper gripper("192.168.2.55");
        gripper.homing();
        franka::GripperState gripper_state = gripper.readOnce();
        double width_max = gripper_state.max_width;
        setDefaultBehavior(robot);                                                                            // 为机器人设置一些默认行为（如碰撞行为、阻尼系数等）
        // First move the robot to a suitable joint configuration
        std::array<double, 7> q_initial = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};                     // q_goal 是一个数组，定义了机器人各个关节的目标角度
        MotionGenerator motion_generator(0.1, q_initial);                                                        // MotionGenerator 是运动生成器，用于生成使机器人到达目标关节配置的运动轨迹。这里的0.5是运动速度的缩放因子
        std::cout << "WARNING: This example will move the robot!"
                  << "Please make sure to have the user stop button at hand!" << std::endl
                  << "Press Enter to continue..." << std::endl;
        std::cin.ignore();
        robot.control(motion_generator);
        std::cout << "Finished moving to initial joint configuration." << std::endl;

        // Set additional parameters always before the control loop, NEVER in the control loop!
        // Set collision behavior.
        robot.setCollisionBehavior(
            {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
            {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
            {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}},
            {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}});
        
        // std::array<double, 7> q_goal = {{0.106986,  0.450258, -0.10919334, -1.95313588,  0.        , 2.00853332,  0.92102655}};
        // MotionGenerator motion_generator2(0.1, q_goal);
        // robot.control(motion_generator2);


        std::array<double, 7> q_goal = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};

        q_goal[0] = q_buf[0];
        q_goal[1] = q_buf[1];
        q_goal[2] = q_buf[2];
        q_goal[3] = q_buf[3];
        q_goal[4] = q_buf[4];
        q_goal[5] = q_buf[5];
        q_goal[6] = q_buf[6];

        MotionGenerator motion_generator1(0.1, q_goal);
        robot.control(motion_generator1);

        
     

        

        double grasping_width =0.04;
        bool homing;
      
        // gripper.homing();

        // Check for the maximum grasping width.
        gripper_state = gripper.readOnce();
        if (gripper_state.max_width < grasping_width) {
          std::cout << "Object is too large for the current fingers on the gripper." << std::endl;

          std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
          MotionGenerator motion_generator3(0.1, q_initial1);  
          robot.control(motion_generator3);
          
          return -1;
        }
        // Grasp the object.
        // gripper.grasp(grasping_width, 0.1, 1, 0.1, 0.1);
        if (!gripper.grasp(grasping_width, 0.1, 1, 0.06, 0)) {
          std::cerr << "Failed to grasp object." << std::endl;

          std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
          MotionGenerator motion_generator3(0.1, q_initial1);  
          robot.control(motion_generator3);

          return -1;
        }
        // gripper.stop();
        // Wait 3s and check afterwards, if the object is still grasped.
        std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(3000));
        gripper_state = gripper.readOnce();
        if (!gripper_state.is_grasped) {
          std::cerr << "Object lost." << std::endl;

          std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
          MotionGenerator motion_generator3(0.1, q_initial1);  
          robot.control(motion_generator3);
          gripper.homing();
          return -1;
        }
        std::cerr << "Grasped object, will release it now." << std::endl;
        // gripper.stop();

        

        std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
        MotionGenerator motion_generator3(0.1, q_initial1);  
        robot.control(motion_generator3);
        gripper.move(width_max, 0.1);  // 2222222222222222222
        gripper.stop();
        // gripper.homing();
        
      } catch (const franka::Exception& e) { 
        std::cout << e.what() << std::endl;
        return -1;
      }
      return 0;
    }
  private:
    void topic_callback(const grasp_msg::msg::GraspMessage::SharedPtr msg) 
    {
      for(int i=0; i<3; i++){      
        std::array<double, 7> q_buf = msg->q_buf[i].joint_pos;
        int r = grasp(q_buf);

        // if(r != -1){
        //   break;
        // }

      }
      // std::cerr<<"sucess!!!!!!\n\n\n\n\n";

    }
    rclcpp::Subscription<grasp_msg::msg::GraspMessage>::SharedPtr subscription_;
};




int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GraspSubscriber>());
  rclcpp::shutdown();
  return 0;
}





// #include <cmath>
// #include <iostream>
// #include <franka/exception.h>
// #include <franka/robot.h>
// #include <franka/gripper.h>
// #include <rclcpp/rclcpp.hpp>
// #include <eigen3/Eigen/Eigen>
// #include "examples_common.h"
// #include "grasp_msg/msg/grasp_message.hpp"
// class GraspSubscriber : public rclcpp::Node
// {
//   public:
//     GraspSubscriber()
//     : Node("grasp_subscriber")
//     {
//       subscription_ = this->create_subscription<grasp_msg::msg::GraspMessage>(
//       "grasp_position", 10, std::bind(&GraspSubscriber::topic_callback, this, std::placeholders::_1));
//       std::array<double, 7> q_buf = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
//       // grasp(q_buf);
//     }
//     int grasp(std::vector<std::array<double, 7>> q_buf) {
//       // std::cerr << "grasps position:\n" << translation{};

//       try {
//         franka::Robot robot("192.168.2.55");
//         franka::Gripper gripper("192.168.2.55");

//         setDefaultBehavior(robot);                                                                            // 为机器人设置一些默认行为（如碰撞行为、阻尼系数等）
//         // First move the robot to a suitable joint configuration
//         std::array<double, 7> q_initial = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};                     // q_goal 是一个数组，定义了机器人各个关节的目标角度
//         MotionGenerator motion_generator(0.1, q_initial);                                                        // MotionGenerator 是运动生成器，用于生成使机器人到达目标关节配置的运动轨迹。这里的0.5是运动速度的缩放因子
//         std::cout << "WARNING: This example will move the robot!"
//                   << "Please make sure to have the user stop button at hand!" << std::endl
//                   << "Press Enter to continue..." << std::endl;
//         std::cin.ignore();
//         robot.control(motion_generator);
//         std::cout << "Finished moving to initial joint configuration." << std::endl;

//         // Set additional parameters always before the control loop, NEVER in the control loop!
//         // Set collision behavior.
//         robot.setCollisionBehavior(
//             {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
//             {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
//             {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}},
//             {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}});
        
//         // std::array<double, 7> q_goal = {{0.2354583,  0.35355366, -0.46735975, -1.94736846,  0.        , 1.3310286,  0.00765905}};
//         // MotionGenerator motion_generator2(0.1, q_goal);
//         // robot.control(motion_generator2);


//         std::array<double, 7> q_goal = {{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}};
        
//         for(int i=0; i<3; i++){
//           q_goal[0] = q_buf[i][0];
//           q_goal[1] = q_buf[i][1];
//           q_goal[2] = q_buf[i][2];
//           q_goal[3] = q_buf[i][3];
//           q_goal[4] = q_buf[i][4];
//           q_goal[5] = q_buf[i][5];
//           q_goal[6] = q_buf[i][6];

//           MotionGenerator motion_generator1(0.1, q_goal);
//           robot.control(motion_generator1);
        
        

//           double grasping_width = 0.10;
//           bool homing;
      
//           gripper.homing();

//           // Check for the maximum grasping width.
//           franka::GripperState gripper_state = gripper.readOnce();
//           if (gripper_state.max_width < grasping_width) {
//             std::cout << "Object is too large for the current fingers on the gripper." << std::endl;

//             std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
//             MotionGenerator motion_generator3(0.1, q_initial1);  
//             robot.control(motion_generator3);
          
//             continue;
//             // return -1;
//           }
//           // Grasp the object.
//           if (!gripper.grasp(grasping_width, 0.1, 0.1)) {
//             std::cout << "Failed to grasp object." << std::endl;

//             std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
//             MotionGenerator motion_generator3(0.1, q_initial1);  
//             robot.control(motion_generator3);

//             continue;
//             // return -1;
//           }
//           // Wait 3s and check afterwards, if the object is still grasped.
//           std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(3000));
//           gripper_state = gripper.readOnce();
//           if (!gripper_state.is_grasped) {
//             std::cout << "Object lost." << std::endl;

//             std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
//             MotionGenerator motion_generator3(0.1, q_initial1);  
//             robot.control(motion_generator3);

//             continue;
//             // return -1;
//           }
//           std::cout << "Grasped object, will release it now." << std::endl;
//           // gripper.stop();

        

//           std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
//           MotionGenerator motion_generator3(0.1, q_initial1);  
//           robot.control(motion_generator3);
        
//           // gripper.homing();
//           break;

//         }
        
//       } catch (const franka::Exception& e) { 
//         std::cout << e.what() << std::endl;
//         return -1;
//       }
//       return 0;
//     }
//   private:
//     void topic_callback(const grasp_msg::msg::GraspMessage::SharedPtr msg) 
//     {
//       // std::array<double, 7> q_buf = msg->q_buf.joint_pos;
//       std::vector<std::array<double, 7>> q_buf = msg->q_buf.joint_pos;
//       grasp(q_buf);
//     }
//     rclcpp::Subscription<grasp_msg::msg::GraspMessage>::SharedPtr subscription_;
// };




// int main(int argc, char * argv[])
// {
//   rclcpp::init(argc, argv);
//   rclcpp::spin(std::make_shared<GraspSubscriber>());
//   rclcpp::shutdown();
//   return 0;
// }





























// int main(int argc, char ** argv){
//   rclcpp::init(argc, argv);
//   auto node = std::make_shared<rclcpp::Node>("grasp_subscriber");
//   rclcpp::spin(node);
//   rclcpp::shutdown();
// }



    // // Set additional parameters always before the control loop, NEVER in the control loop!
    // // Set collision behavior.
    // robot.setCollisionBehavior(
    //     {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
    //     {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
    //     {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}},
    //     {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}});
    
    // // 在这个控制循环中，机器人将在笛卡尔空间中执行一个简单的周期运动（一个圆弧）
    // std::array<double, 16> initial_pose;
    // double time = 0.0;
    // robot.control([&time, &initial_pose](const franka::RobotState& robot_state,
    //                                      franka::Duration period) -> franka::CartesianPose {
    //   time += period.toSec();
    //   if (time == 0.0) {                                                                                  // 在时间time为0时，获取机器人的初始姿态initial_pose
    //     initial_pose = robot_state.O_T_EE_c;
    //   }
    //   constexpr double kRadius = 0.3;
    //   double angle = M_PI / 4 * (1 - std::cos(M_PI / 5.0 * time));
    //   double delta_x = kRadius * std::sin(angle);
    //   double delta_z = kRadius * (std::cos(angle) - 1);
    //   std::array<double, 16> new_pose = initial_pose;
    //   new_pose[12] += delta_x;
    //   new_pose[14] += delta_z;
    //   if (time >= 10.0) {                                                                                 // 当时间达到10秒时，结束运动，并通过franka::MotionFinished返回最终姿态来停止机器人
    //     std::cout << std::endl << "Finished motion, shutting down robot" << std::endl;
    //     return franka::MotionFinished(new_pose);
    //   }
    //   return new_pose;
    // });








// int main(int argc, char** argv) {
//     std::cout<<"hello world";
//     // if (argc != 2) {
//     // std::cerr << "Usage: " << argv[0] << "IP-Address" << std::endl;
//     // return -1;
//     // }
//     try
//     {
//         franka::Robot robot("192.168.2.55");
//         franka::Gripper gripper("192.168.2.55");

//         // 设置接触和碰撞检测阈值，始终在控制循环之前设置附加参数，切勿在控制循环中设置！
//         robot.setCollisionBehavior(
//             {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
//             {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}}, {{20.0, 20.0, 18.0, 18.0, 16.0, 14.0, 12.0}},
//             {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}},
//             {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}}, {{20.0, 20.0, 20.0, 25.0, 25.0, 25.0}});
//         // 设置内部笛卡尔阻抗和内部联合阻抗控制器的阻抗参数
//         robot.setJointImpedance({{3000, 3000, 3000, 2500, 2500, 2000, 2000}});
//         robot.setCartesianImpedance({{3000, 3000, 3000, 300, 300, 300}});

//         // First move the robot to a suitable joint configuration
//         std::array<double, 7> q_goal = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};
//         MotionGenerator motion_generator(0.5, q_goal);

//         std::cout << "Please make sure to have the user stop button at hand!" << std::endl
//                 << "Press Enter to continue..." << std::endl;
//         std::cin.ignore();

//         // callback function
//         std::array<double, 7> initial_position;
//         double time = 0.0;
//         robot.control([&initial_position, &time](const franka::RobotState& robot_state, franka::Duration period) -> franka::JointPositions {
//             time += period.toSec();                                                                                // Update time at the beginning of the callback
//             if (time == 0.0) {
//                 initial_position = robot_state.q_d;
//             }
//             double delta_angle = M_PI / 8.0 * (1 - std::cos(M_PI / 2.5 * time));
//             franka::JointPositions output = {{initial_position[0], initial_position[1],
//                                             initial_position[2], initial_position[3],
//                                             initial_position[4], initial_position[5],
//                                             initial_position[6] + delta_angle}};
//             if (time >= 5) {
//                 std::cout << std::endl << "Finished motion, shutting down robot" << std::endl;
//                 return franka::MotionFinished(output);                                                             // Return MotionFinished at the end of the trajectory
//             }
//             return output;
//         }); 


//     }
//     // 如果发生任何错误（无论是由于网络还是库版本冲突），franka::Exception都会抛出类型的异常
//     catch(const franka::Exception& e)
//     {
//         std::cout << e.what() << std::endl;
//         return -1;
//     }
//     return 0;
// }