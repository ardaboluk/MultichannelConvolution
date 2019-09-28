
#include "kernel3.h"
#include <exception>

Kernel3::Kernel3(cv::Mat* cvMatrix) {
	if (cvMatrix == NULL) {
		throw std::invalid_argument("cv::Mat object cannot be null. Kernel3.");
	}
	else if (cvMatrix->channels() != 3) {
		throw std::invalid_argument("cv::Mat object should have 3 channels. Kernel3.");
	}
	else if ((cvMatrix->rows != cvMatrix->cols) || (cvMatrix->rows % 2 == 0)) {
		throw std::invalid_argument("cv::Mat should be square matrix of odd size. Kernel3.");
	}
	dataWrapper = new DataWrapper<cv::Mat>(cvMatrix);
}

Kernel3::~Kernel3() {
	delete this->dataWrapper;
}

int Kernel3::getWidth() const {
	return this->dataWrapper->getData()->cols;
}

int Kernel3::getHeight() const {
	return this->dataWrapper->getData()->rows;
}

int Kernel3::getDepth() const {
	return dataWrapper->getData()->channels();
}

DataWrapper<cv::Mat>* Kernel3::getDataWrapper() const {
	return dataWrapper;
}