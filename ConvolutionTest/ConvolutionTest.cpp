
#include <iostream>
#include <exception>

#include "opencv2/opencv.hpp"
#include "kernel3.h"
#include "image3.h"
#include "convolution3.h"
#include "util.h"
#include "point.h"
#include "rectangle.h"

int main()
{
	try {
		cv::Mat imageData = cv::imread("image_for_part_2.jpg");
		Image3* image = new Image3(&imageData);
		Kernel3* kernel = Util::readKernel3FromFile("kernel3.txt");

		Convolution3 conv3(image, kernel);

		Point p1(0, 0);
		Point p2(image->getWidth() - 1, image->getHeight() - 1);
		Rectangle wholeImageRegion(p1, p2);
		Image3* resultImage = conv3.convolute(wholeImageRegion);

		cv::imwrite("./filtered.jpg", *(resultImage->getData()->getData()));
		cv::namedWindow("Filtered Image");
		cv::imshow("Filtered Image", *(resultImage->getData()->getData()));
		cv::waitKey(0);

		delete image;
		delete kernel;
	}
	catch (const std::exception& e) {
		std::cout<<e.what();
	}

	return 0;
}