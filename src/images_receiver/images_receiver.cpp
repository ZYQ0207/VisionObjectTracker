#include "images_receiver.hpp"


ImageReceiver::~ImageReceiver(){}


ImageReceiver::ImageReceiver(ros::NodeHandle &n):
  it_(n)
{
  //basic configuration
  image_sub_ = it_.subscribe("/image_raw", 10, &ImageReceiver::image_callback, this);
  image_index = 1;

  //initiate KCF tracker
  KCFFrameTracker tracker(cv::Rect(246, 226, 94, 114));
  this->tracker = tracker;
}


void ImageReceiver::image_callback(const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  cv::Rect result_rect;
  //receive the frame
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::RGB8);
  }
  catch (cv_bridge::Exception e)
  {
    ROS_ERROR("cv_bridge exception %s", e.what());
    return;
  }
  //use the image train the tracker and get the roi of target
  result_rect = tracker.track(cv_ptr->image);
  //draw the rect on the image


}
