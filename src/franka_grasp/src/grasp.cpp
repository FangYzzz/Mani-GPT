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
      try {
        franka::Robot robot("192.168.2.55");
        franka::Gripper gripper("192.168.2.55");
        gripper.homing();
        franka::GripperState gripper_state = gripper.readOnce();
        double width_max = gripper_state.max_width;

        // ***arm***
        setDefaultBehavior(robot);                                                                            
        // First move the robot to a suitable joint configuration
        std::array<double, 7> q_initial = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};                     
        MotionGenerator motion_generator(0.1, q_initial);                                                        
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

        // ***gripper***
        double grasping_width = 0.04;
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

        std::array<double, 7> q_initial1 = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};  
        MotionGenerator motion_generator3(0.1, q_initial1);  
        robot.control(motion_generator3);
        gripper.move(width_max, 0.1);  
        gripper.stop();
        
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
      }
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


