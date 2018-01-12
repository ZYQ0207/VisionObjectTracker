#include "images_receiver.hpp"


ImageReceiver::~ImageReceiver()
{
  cv::destroyWindow(OPENCV_WINDOW);
}


ImageReceiver::ImageReceiver(ros::NodeHandle &n):
  it_(n)
{
  //basic configuration
  image_sub_ = it_.subscribe("/image_raw", 25, &ImageReceiver::image_callback, this);
  image_index = 1;
  cv::namedWindow(OPENCV_WINDOW);

  //initiate KCF tracker
  this->tracker = new KCFFrameTracker(cv::Rect(246, 226, 94, 114));
  //this->tracker = new KCFFrameTracker(cv::Rect(146, 54, 68, 101));
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
  result_rect = tracker->track(cv_ptr->image);
  //draw the rect on the image
  cv::rectangle(cv_ptr->image, result_rect, cv::Scalar(0, 255, 255), 2, 8);
  //show the result on the picture
  cv::imshow(OPENCV_WINDOW, cv_ptr->image);
  cv::waitKey(1);//this number connot be too large

}
