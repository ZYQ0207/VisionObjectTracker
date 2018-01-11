#ifndef _IMAGE_RECEIVER_HPP_
#define _IMAGE_RECEIVER_HPP_


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/image_encodings.h>
#include <sstream>
#include <dirent.h>

//Algorithm of trackers
#include "../kcf/kcf_tracker/kcf_tracker.hpp"


class ImageReceiver
{

public:
  ImageReceiver(ros::NodeHandle &n);
  ~ImageReceiver();
  void image_callback(const sensor_msgs::ImageConstPtr &msg);

private:
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  int image_index;

  //reference of trackers can be added here
  KCFFrameTracker &tracker;

}


#endif
