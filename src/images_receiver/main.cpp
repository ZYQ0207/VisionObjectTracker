#include "images_receiver.hpp"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "tracker");
  ros::NodeHandle n;

  ImageReceiver ir(n);

  ros::spin();
  return 0;
}
