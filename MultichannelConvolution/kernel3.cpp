
#include "kernel3.h"
#include <exception>

Kernel3::Kernel3(cv::Mat* cvMatrix) {
	if (cvMatrix == NULL) {
		throw std::invalid_argument("cv::Mat object cannot be null.");
	}
	else if (cvMatrix->channels() != 3) {
		throw std::invalid_argument("cv::Mat object should have 3 channels.");
	}
	else if ((cvMatrix->rows != cvMatrix->cols) || (cvMatrix->rows % 2 == 0)) {
		throw std::invalid_argument("cv::Mat should be square matrix of odd size.");
	}
	data = new Data<cv::Mat>(cvMatrix);
}

Kernel3::~Kernel3() {
	delete this->data;
}

int Kernel3::getWidth() const {
	return this->data->getData()->cols;
}

int Kernel3::getHeight() const {
	return this->data->getData()->rows;
}

int Kernel3::getDepth() const {
	return data->getData()->channels();
}

Data<cv::Mat>* Kernel3::getData() const {
	return data;
}