
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

void getFileNamesFromUser();

int main(int argc, char *argv[])
{
	try {
		
		if (argc > 2) {
			imageFileName = argv[1];
			kernelFileName = argv[2];
		}
		else {
			getFileNamesFromUser();
		}
		char delim[1] = { '.' };
		resultImageFileName = imageFileName.substr(0, imageFileName.find("."));
		resultImageFileName += "_filtered.jpg";

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
		cout << double(end - begin) / CLOCKS_PER_SEC;

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
		cout<<e.what();
	}

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