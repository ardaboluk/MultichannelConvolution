
#include "image3.h"
#include <exception>

Image3::Image3(cv::Mat* cvMatrix){
	if (cvMatrix == NULL) {
		throw std::invalid_argument("cv::Mat object cannot be null. Image3.");
	}
	else if(cvMatrix->channels() != 3){
		throw std::invalid_argument("cv::Mat object should have 3 channels. Image3.");
	}
	dataWrapper = new DataWrapper<cv::Mat>(cvMatrix);
}

Image3::~Image3() {
	delete this->dataWrapper;
}

int Image3::getWidth() const {
	return this->dataWrapper->getData()->cols;
}

int Image3::getHeight() const {
	return this->dataWrapper->getData()->rows;
}

int Image3::getDepth() const {
	return dataWrapper->getData()->channels();
}

DataWrapper<cv::Mat>* Image3::getDataWrapper() const {
	return dataWrapper;
}