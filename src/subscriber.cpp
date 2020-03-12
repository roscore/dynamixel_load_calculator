#include <ros/ros.h>
#include <stdio.h>
#include "dynamixel_load_calculator/dynamixel_load_calculator.h" 

void LeftTorqueCallBack(const ssoni_arm_module_msgs::SixJointTorque::ConstPtr& msg)
{
  ROS_INFO("ID 1 joint's current is %f mA", (msg->torque[0])*1);
  ROS_INFO("ID 3 joint's currnet is %f mA", (msg->torque[1])*2.69);
  ROS_INFO("ID 5 joint's currnet is %f mA", (msg->torque[2])*2.69);
  ROS_INFO("ID 7 joint's currnet is %f mA", (msg->torque[3])*2.69);
  ROS_INFO("ID 9 joint's currnet is %f mA", (msg->torque[4])*2.69);
  ROS_INFO("ID 11 joint's currnet is %f mA", (msg->torque[5])*2.69);

  total_current = abs(msg->torque[0])*1 + (abs(msg->torque[1]) + abs(msg->torque[2]) + abs(msg->torque[3]) + abs(msg->torque[4]) + abs(msg->torque[5]))*2.69;

  if(total_current > 1000)
  {
    ROS_INFO("                                                                                           range in A");
  }

  ROS_INFO("total current is %f mA", total_current);

  /*
  for(int i=0; i<6; i++)
  {
    if(i=0)
    {
      //ROS_INFO("ID %d joint's current is %f mA", (i*2-1)+2, (msg->torque[i]));
    }
    else if(i < 6)
    {
      ROS_INFO("%d",i);
      //ROS_INFO("ID %d joint's current is %f mA", (i*2-1)+2, (msg->torque[i]*2.69));
    } 
  }
  */ 
}

void RightTorqueCallBack(const ssoni_arm_module_msgs::SixJointTorque::ConstPtr& msg)
{
  for(int i=0; i<6; i++)
  {
    if(i=0)
    {
      ROS_INFO("ID %d joint's current is %f mA", (i+1)*2, (msg->torque[i]*1));
    }
    else
    {
      ROS_INFO("ID %d joint's current is %f mA", (i+1)*2, (msg->torque[i]*2.69));
    } 
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;

  ros::Rate rate(1000.);

  l_torque_sub = nh.subscribe("left_arm/torque", 1000, LeftTorqueCallBack);
  //r_torque_sub = nh.subscribe("right_arm/torque", 1000, RightTorqueCallBack); 

  while(ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
  }

}
