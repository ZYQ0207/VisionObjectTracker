#include "kcf_tracker.hpp"


KCFFrameTracker::KCFFrameTracker(cv::Rect init_rect)
{
  KCFTracker tracker(HOG, FIXEDWINDOW, MULTISCALE, LAB);
  tracker_ptr = &tracker;
  result_rect = init_rect;
}


KCFFrameTracker::~KCFFrameTracker(){}


cv::Rect KCFFrameTracker::track(cv::Mat frame)
{
  if(frame_index==1)
  {
    tracker_ptr->init(result_rect, frame);
  }
  else
  {
    result_rect = tracker_ptr->update(frame);
  }
  frame_index++;

  return result_rect;
}

