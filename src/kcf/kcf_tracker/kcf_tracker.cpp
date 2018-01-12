#include "kcf_tracker.hpp"
#include <iostream>

KCFFrameTracker::KCFFrameTracker(cv::Rect init_rect)
{
  tracker_ptr = new KCFTracker(HOG, FIXEDWINDOW, MULTISCALE, LAB);
  result_rect = init_rect;
  frame_index = 1;
  //parameters for KCF tracker
  HOG = true;
  FIXEDWINDOW = false;
  MULTISCALE = true;
  LAB = false;
}


KCFFrameTracker::~KCFFrameTracker(){}


cv::Rect KCFFrameTracker::track(cv::Mat frame)
{
  std::cout << frame_index << std::endl;
  if(frame_index==1)
  {
    tracker_ptr->init(result_rect, frame);
  }
  else if(frame_index > 1)
  {
    result_rect = tracker_ptr->update(frame);
  }
  frame_index++;
  return result_rect;
}

