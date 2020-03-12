#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <std_msgs/Int16.h>
#include <boost/thread.hpp>

#include "robotis_framework_common/motion_module.h"
#include "ssoni_arm_module_msgs/SixJointTorque.h"

  ros::Subscriber l_torque_sub;
  ros::Subscriber r_torque_sub;

  void RightTorqueCallBack(const ssoni_arm_module_msgs::SixJointTorque::ConstPtr& msg);
  void LeftTorqueCallBack(const ssoni_arm_module_msgs::SixJointTorque::ConstPtr& msg);

  float total_current;
