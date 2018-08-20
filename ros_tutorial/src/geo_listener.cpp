#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"


void chatterCallback(const geometry_msgs::Point::ConstPtr& msg)
{
  //ROS_INFO("I heard: x[%s], y[%s], z[%s]", msg.x.c_str(), msg.y.c_str(), msg.z.c_str());
  int ix = (int) msg->x;
  int iy = (int) msg->y;
  int iz = (int) msg->z;
  printf("I heard: x[%d], y[%d], z[%d] \n", ix, iy, iz);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "geo_listener");


  ros::NodeHandle n;


  ros::Subscriber sub = n.subscribe("homework", 1000, chatterCallback);


  ros::spin();

  return 0;
}
