
#include "convolution3.h"
#include <exception>

Convolution3::Convolution3(Image3* image, Kernel3* kernel) {

	if (image == NULL) {
		throw std::invalid_argument("Image3 object cannot be null.");
	}

	if (kernel == NULL) {
		throw std::invalid_argument("Kernel3 object cannot be null.");
	}

	if ((image->getWidth() * image->getHeight()) < (kernel->getWidth() * image->getHeight())) {
		throw std::invalid_argument("Image cannot be smaller than kernel.");
	}

	this->image = image;
	this->kernel = kernel;
}

Image3* Convolution3::convolute(Rectangle convRegion) const{
	if (convRegion.getArea() < (kernel->getWidth() * kernel->getHeight())) {
		throw new std::invalid_argument("Region cannot be smaller than the kernel.");
	}
	else if (convRegion.getArea() > (image->getWidth() * image->getHeight())) {
		throw new std::invalid_argument("Region cannot be larger than the image.");
	}


}