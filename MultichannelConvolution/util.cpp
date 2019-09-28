
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>

#include "opencv2/opencv.hpp"
#include "util.h"

using namespace std;

Kernel3* Util::readKernel3FromFile(string fileName) {
	
	Kernel3* kernel = NULL;
	cv::Mat* kernelData = NULL;

	int kernelWidth = 0, kernelHeight = 0, kernelDepth = 0;

	ifstream infile;

	infile.open(fileName);
	if (!infile) {
		throw runtime_error("File not found.");
	}

	infile >> kernelWidth;
	infile >> kernelHeight;
	infile >> kernelDepth;

	if (kernelWidth <= 0 || kernelHeight <= 0 || kernelDepth != 3) {
		throw invalid_argument("Invalid kernel.");
	}

	kernelData = new cv::Mat(kernelHeight, kernelWidth, CV_32FC3);
	
	for (int channel = 0; channel < kernelDepth; channel++) {
		for (int row = 0; row < kernelHeight; row++) {
			for (int col = 0; col < kernelWidth; col++) {
				float* kernel_current_elemnt_ptr = kernelData->ptr<float>(row) + col * kernelDepth + channel;
				infile >> *kernel_current_elemnt_ptr;
			}
		}
	}

	kernel = new Kernel3(kernelData);

	return kernel;
}