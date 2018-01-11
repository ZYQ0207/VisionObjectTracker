#ifndef _IMAGE_SENDER_HPP_
#define _IMAGE_SENDER_HPP_


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/image_encodings.h>
#include <sstream>
#include <iostream>


class ImageSender
{
public:

  ImageSender(std::string path, ros::NodeHandle &n);
  ~ImageSender();
  void image_send(const ros::TimerEvent&);
  std::string get_image_path(void);

private:

  cv::Mat cv_image_;
  image_transport::ImageTransport it_;
  image_transport::Publisher image_pub_;
  std::ostringstream image_path_;
  int image_index;
};


#endif
