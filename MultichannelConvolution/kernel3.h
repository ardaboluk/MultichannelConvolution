#pragma once

#include "opencv2/opencv.hpp"
#include "kernel.h"

using namespace conv;

class Kernel3 : public Kernel<cv::Mat> {
private:
	Data<cv::Mat>* data;
public:
	Kernel3(cv::Mat*);
	~Kernel3();

	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
	Data<cv::Mat>* getData() const;
};