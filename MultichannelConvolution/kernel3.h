#pragma once

#include "opencv2/opencv.hpp"
#include "kernel.h"

using namespace conv;

class Kernel3 : public Kernel<cv::Mat> {
private:
	DataWrapper<cv::Mat>* dataWrapper;
public:
	Kernel3(cv::Mat*);
	~Kernel3();

	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
	DataWrapper<cv::Mat>* getDataWrapper() const;
};