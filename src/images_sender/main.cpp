#include "image_sender.hpp"



int main(int argc, char** argv)
{
  // initiate the rosnode
  ros::init(argc, argv, "iamge_sender");
  ros::NodeHandle n;

  ImageSender image_sender("/mnt/hgfs/ROS_Share/BlurFace/img", n);
  //ImageSender image_sender("/mnt/hgfs/ROS_Share/Trellis/img", n);

  //send frequency: 25 Hz
  ros::Timer timer = n.createTimer(ros::Duration(0.04), &ImageSender::image_send, &image_sender);

  ros::spin();
  return 0;
}
