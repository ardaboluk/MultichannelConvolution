
#include <iostream>
#include <exception>
#include <ctime>

#include "opencv2/opencv.hpp"
#include "kernel3.h"
#include "image3.h"
#include "convolution3.h"
#include "util.h"
#include "point.h"
#include "rectangle.h"

using namespace std;

string imageFileName;
string kernelFileName;
string resultImageFileName;
string resultImgeFileNameOpenCV;

void getFileNamesFromUser();
void testCustomModule();
void testOpenCV();

int main(int argc, char *argv[])
{		
	if (argc > 2) {
		imageFileName = argv[1];
		kernelFileName = argv[2];
	}
	else {
		getFileNamesFromUser();
	}
	resultImageFileName = imageFileName.substr(0, imageFileName.find("."));
	resultImgeFileNameOpenCV = string(resultImageFileName);
	resultImageFileName += "_filtered.jpg";
	resultImgeFileNameOpenCV += "_filtered_opencv.jpg";

	testCustomModule();
	testOpenCV();

	return 0;
}

void getFileNamesFromUser() {

	string outputFileName = "";

	cout << "Please enter the file name of the image." << endl;
	string tmp = "";
	while (tmp == "") {
		cin >> tmp;
	}
	imageFileName = tmp;

	cout << "Please enter the file name of the kernel." << endl;
	tmp = "";
	while (tmp == "") {
		cin >> tmp;
	}
	kernelFileName = tmp;
}

void testCustomModule() {
	try {
		cv::Mat imageData = cv::imread(imageFileName);
		Image3* image = new Image3(&imageData);
		Kernel3* kernel = Util::readKernel3FromFile(kernelFileName);

		Convolution3 conv3(image, kernel);

		Point p1(0, 0);
		Point p2(image->getWidth() - 1, image->getHeight() - 1);
		Rectangle wholeImageRegion(p1, p2);

		clock_t begin = clock();
		Image3* resultImage = conv3.convolute(wholeImageRegion);
		clock_t end = clock();
		cout << "Elapsed time in convolution: " << endl;
		cout << double(end - begin) / CLOCKS_PER_SEC << endl;

		cv::imwrite(resultImageFileName, *(resultImage->getDataWrapper()->getData()));
		cv::namedWindow("Filtered Image");
		cv::imshow("Filtered Image", *(resultImage->getDataWrapper()->getData()));
		cv::waitKey(0);

		imageData.release();
		kernel->getDataWrapper()->getData()->release();
		resultImage->getDataWrapper()->getData()->release();

		delete image;
		delete kernel;
		delete resultImage;
	}
	catch (const exception& e) {
		cout << e.what();
	}
}

void testOpenCV() {

	cv::Point anchor(-1, -1);
	double delta = 0;
	int borderType = cv::BORDER_REFLECT;

	cv::Mat imgOriginal = cv::imread(imageFileName);
	cv::Mat imgFilteredSplit[3] = { {imgOriginal.size(), CV_8UC1}, {imgOriginal.size(), CV_8UC1}, {imgOriginal.size(), CV_8UC1} };
	cv::Mat bgrChannel[3];
	cv::Mat imgFiltered;
	cv::split(imgOriginal, bgrChannel);

	cv::Mat kernelB(3, 3, CV_32FC1), kernelG(3, 3, CV_32FC1), kernelR(3, 3, CV_32FC1);
	Kernel3* kernel = Util::readKernel3FromFile(kernelFileName);
	cv::Size kernelSize = kernel->getDataWrapper()->getData()->size();
	cv::Mat kernelChannel[3] = { {kernelSize, CV_8UC1}, {kernelSize, CV_8UC1}, {kernelSize, CV_8UC1} };;
	cv::split(*kernel->getDataWrapper()->getData(), kernelChannel);
	kernelB = kernelChannel[0];
	kernelG = kernelChannel[1];
	kernelR = kernelChannel[2];

	clock_t begin = clock();
	filter2D(bgrChannel[0], imgFilteredSplit[0], -1, kernelB, anchor, delta, borderType);
	filter2D(bgrChannel[1], imgFilteredSplit[1], -1, kernelG, anchor, delta, borderType);
	filter2D(bgrChannel[2], imgFilteredSplit[2], -1, kernelR, anchor, delta, borderType);
	clock_t end = clock();
	cout << "Elapsed time in convolution in OpenCV: " << endl;
	cout << double(end - begin) / CLOCKS_PER_SEC << endl;

	cv::merge(&(imgFilteredSplit[0]), 3, imgFiltered);

	cv::namedWindow("Filtered Image OpenCV", cv::WINDOW_NORMAL);
	imshow("Filtered Image OpenCV", imgFiltered);
	imwrite(resultImgeFileNameOpenCV, imgFiltered);
	cv::waitKey(0);

	imgOriginal.release();
	kernel->getDataWrapper()->getData()->release();
	imgFiltered.release();
	kernelB.release();
	kernelG.release();
	kernelR.release();

	delete kernel;
}