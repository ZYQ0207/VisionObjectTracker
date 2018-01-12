#ifndef _KCF_TRACKER_HPP_
#define _KCF_TRACKER_HPP_

#include <opencv2/core/core.hpp>
#include "../kcf_source/kcftracker.hpp"

class KCFFrameTracker
{
public:
  KCFFrameTracker(cv::Rect init_rect);
  ~KCFFrameTracker();
  cv::Rect track(cv::Mat frame);

private:
  //the pointer that point to the KCF tracker
  KCFTracker *tracker_ptr;
  //the number of frame to be detected
  int frame_index;
  //the init location and the continous result
  cv::Rect result_rect;
  //parameters of tracker
  bool HOG;
  bool FIXEDWINDOW;
  bool MULTISCALE;
  bool LAB;
};

#endif
