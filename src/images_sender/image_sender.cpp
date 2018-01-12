#include "image_sender.hpp"


ImageSender::ImageSender(std::string path, ros::NodeHandle &n):
  it_(n)
{
  image_pub_ = it_.advertise("/image_raw", 1);
  image_index = 1;
  image_path_ << path;
}


ImageSender::~ImageSender(){}


void ImageSender::image_send(const ros::TimerEvent&)
{
  sensor_msgs::ImagePtr imgmsg;

  cv::Mat cv_img = cv::imread(get_image_path(), CV_LOAD_IMAGE_UNCHANGED);
  imgmsg = cv_bridge::CvImage(std_msgs::Header(), "rgb8", cv_img).toImageMsg();
  image_pub_.publish(imgmsg);
  //refresh the image index (from 0001.jpg to 0xxx.jpg)
  image_index ++;
}


std::string ImageSender::get_image_path(void)
{
  std::ostringstream path_output;
  if(image_index>=100)
  {
    path_output << image_path_.str() << "/0" << image_index << ".jpg";
  }
  else if(image_index>=10 && image_index<100)
  {
    path_output << image_path_.str() << "/00" << image_index << ".jpg";
  }
  else
  {
    path_output << image_path_.str() << "/000" << image_index << ".jpg";
  }
  return path_output.str();
}

