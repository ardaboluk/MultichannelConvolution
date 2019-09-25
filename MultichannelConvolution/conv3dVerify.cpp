#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Point anchor(-1, -1);
	double delta = 0;
	int borderType = BORDER_REFLECT;

	Mat imgOriginal = imread("image_for_part_2.jpg");
	Mat imgFilteredSplit[3] = { {imgOriginal.size(), CV_8UC1}, {imgOriginal.size(), CV_8UC1}, {imgOriginal.size(), CV_8UC1} };
	Mat bgrChannel[3];
	Mat imgFiltered;
	split(imgOriginal, bgrChannel);

	Mat kernelB(3, 3, CV_32FC1), kernelG(3, 3, CV_32FC1), kernelR(3, 3, CV_32FC1);

	kernelB.at<float>(0, 0) = 1; kernelB.at<float>(0, 1) = 0; kernelB.at<float>(0, 2) = -1;
	kernelB.at<float>(1, 0) = 2; kernelB.at<float>(1, 1) = 0; kernelB.at<float>(1, 2) = -2;
	kernelB.at<float>(2, 0) = 1; kernelB.at<float>(2, 1) = 0; kernelB.at<float>(2, 2) = -1;

	kernelG.at<float>(0, 0) = 1; kernelG.at<float>(0, 1) = 2; kernelG.at<float>(0, 2) = 1;
	kernelG.at<float>(1, 0) = 2; kernelG.at<float>(1, 1) = 4; kernelG.at<float>(1, 2) = 2;
	kernelG.at<float>(2, 0) = 1; kernelG.at<float>(2, 1) = 2; kernelG.at<float>(2, 2) = 1;

	kernelR.at<float>(0, 0) = 1; kernelR.at<float>(0, 1) = 1; kernelR.at<float>(0, 2) = 1;
	kernelR.at<float>(1, 0) = 1; kernelR.at<float>(1, 1) = 1; kernelR.at<float>(1, 2) = 1;
	kernelR.at<float>(2, 0) = 1; kernelR.at<float>(2, 1) = 1; kernelR.at<float>(2, 2) = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			kernelG.at<float>(i,j) /= 16;
			kernelR.at<float>(i,j) /= 9;
		}
	}

	filter2D(bgrChannel[0], imgFilteredSplit[0], -1, kernelB, anchor, delta, borderType);
	filter2D(bgrChannel[1], imgFilteredSplit[1], -1, kernelG, anchor, delta, borderType);
	filter2D(bgrChannel[2], imgFilteredSplit[2], -1, kernelR, anchor, delta, borderType);

	merge(&(imgFilteredSplit[0]), 3, imgFiltered);

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", imgFiltered);
	imwrite("./filtered_verify.jpg", imgFiltered);
	waitKey(0);

	return 0;
}