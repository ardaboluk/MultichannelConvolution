#pragma once

#include "opencv2/opencv.hpp"
#include "image.h"
#include "datawrapper.h"

using namespace conv;

class Image3 : public Image<cv::Mat> {
private:
	DataWrapper<cv::Mat>* dataWrapper;
public:
	Image3(cv::Mat*);
	~Image3();

	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
	DataWrapper<cv::Mat>* getDataWrapper() const;
};
