#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "geo_talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Point>("homework", 1000);

  ros::Rate loop_rate(5);

  int count = 0;
  while (ros::ok())
  {
    geometry_msgs::Point msg;

    msg.x = 10000+count;
    msg.y = 20000+count;
    msg.z = 30000+count;

    //ROS_INFO("x:%s, y:%s, z:%s", msg.x.c_str(), msg.y.c_str(), msg.z.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
