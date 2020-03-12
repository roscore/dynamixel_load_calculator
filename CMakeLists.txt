cmake_minimum_required(VERSION 2.8.3)
project(dynamixel_load_calculator)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
  robotis_device
  dynamixel_sdk
  robotis_framework_common
  ssoni_arm_module_msgs 
)

catkin_package(
  LIBRARIES dynamixel_load_calculator
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable(dynamixel_load_calculator src/subscriber.cpp)

add_dependencies(dynamixel_load_calculator ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(dynamixel_load_calculator ${catkin_LIBRARIES})
