#pragma once

#include "opencv2/opencv.hpp"
#include "../ConvolutionCore/image.h"
#include "../ConvolutionCore/data.h"

using namespace conv;

class Image3 : public Image<cv::Mat> {
private:
	Data<cv::Mat>* data;
public:
	Image3(cv::Mat*);
	~Image3();

	int getWidth() const;
	int getHeight() const;
	int getDepth() const;
	Data<cv::Mat>* getData() const;
};
