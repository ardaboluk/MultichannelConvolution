#pragma once

#include "opencv2/opencv.hpp"
#include "convolution.h"
#include "rectangle.h"
#include "image3.h"
#include "kernel3.h"

class Convolution3 : public Convolution<cv::Mat> {
private:
	Image3* image;
	Kernel3* kernel;
	cv::Mat borderedImage;
public:
	Convolution3(Image3*, Kernel3*);
	Image3* convolute(Rectangle) const;
};
