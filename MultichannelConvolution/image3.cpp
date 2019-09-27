
#include "image3.h"
#include <exception>

Image3::Image3(cv::Mat* cvMatrix){
	if (cvMatrix == NULL) {
		throw std::invalid_argument("cv::Mat object cannot be null. Image3.");
	}
	else if(cvMatrix->channels() != 3){
		throw std::invalid_argument("cv::Mat object should have 3 channels. Image3.");
	}
	data = new Data<cv::Mat>(cvMatrix);
}

Image3::~Image3() {
	delete this->data;
}

int Image3::getWidth() const {
	return this->data->getData()->cols;
}

int Image3::getHeight() const {
	return this->data->getData()->rows;
}

int Image3::getDepth() const {
	return data->getData()->channels();
}

Data<cv::Mat>* Image3::getData() const {
	return data;
}