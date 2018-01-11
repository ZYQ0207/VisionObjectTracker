#include "image_sender.hpp"



int main(int argc, char** argv)
{
  // initiate the rosnode
  ros::init(argc, argv, "iamge_sender");
  ros::NodeHandle n;

  ImageSender image_sender("/mnt/hgfs/ROS_Share/BlurFace/img", n);
  ros::Timer timer = n.createTimer(ros::Duration(0.03), &ImageSender::image_send, &image_sender);

  ros::spin();
  return 0;
}
