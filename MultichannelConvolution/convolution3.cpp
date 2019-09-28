
#include "convolution3.h"
#include <exception>
#include <cmath>
#include <iostream>

Convolution3::Convolution3(Image3* image, Kernel3* kernel) {

	if (image == NULL) {
		throw std::invalid_argument("Image3 object cannot be null. Convolution3.");
	}

	if (kernel == NULL) {
		throw std::invalid_argument("Kernel3 object cannot be null. Convolution3.");
	}

	if ((image->getWidth() * image->getHeight()) < (kernel->getWidth() * kernel->getHeight())) {
		throw std::invalid_argument("Image cannot be smaller than kernel. Convolution3.");
	}

	this->image = image;
	this->kernel = kernel;

	int borderedImageWidth = image->getWidth() + (kernel->getWidth() - 1);
	int borderedImageHeight = image->getHeight() + (kernel->getHeight() - 1);
	this->borderedImage = cv::Mat(borderedImageHeight, borderedImageWidth, image->getDataWrapper()->getData()->type());
	cv::copyMakeBorder(*image->getDataWrapper()->getData(), borderedImage, kernel->getHeight() / 2, kernel->getHeight() / 2,
		kernel->getWidth() / 2, kernel->getWidth() / 2, cv::BORDER_REFLECT);
}

Image3* Convolution3::convolute(Rectangle convRegion){

	if (convRegion.getArea() < (kernel->getWidth() * kernel->getHeight())) {
		throw std::invalid_argument("Region cannot be smaller than the kernel. Convolution3.");
	}
	else if ((convRegion.getPLeftUpper().getX() < 0) || (convRegion.getPLeftUpper().getY() < 0) ||
		(convRegion.getPRightLower().getX() >= image->getWidth()) || (convRegion.getPRightLower().getY() >= image->getHeight())) {
		throw std::invalid_argument("Region must be inside or on the image. Convolution3.");
	}

	int resultMatRows = abs(convRegion.getPRightLower().getY() - convRegion.getPLeftUpper().getY()) + 1;
	int resultMatCols = abs(convRegion.getPRightLower().getX() - convRegion.getPLeftUpper().getX()) + 1;
	cv::Mat* resultMat = new cv::Mat(resultMatRows, resultMatCols, this->image->getDataWrapper()->getData()->type());

	int startRow = convRegion.getPLeftUpper().getY() + kernel->getHeight() / 2;
	int endRow = convRegion.getPRightLower().getY() + kernel->getHeight() / 2;
	int startCol = convRegion.getPLeftUpper().getX() + kernel->getHeight() / 2;
	int endCol = convRegion.getPRightLower().getX() + kernel->getHeight() / 2;

	cv::Mat* kernel_ptr = kernel->getDataWrapper()->getData();

	for (int currentRow = startRow; currentRow <= endRow; currentRow++) {
		for (int currentCol = startCol; currentCol <= endCol; currentCol++) {
			float sumb = 0, sumg = 0, sumr = 0;
			for (int i = -(kernel->getHeight()/2); i <= kernel->getHeight()/2; i++) {
				uchar* mat_row_ptr = borderedImage.ptr<uchar>(currentRow + i);
				float* kernel_row_ptr = kernel_ptr->ptr<float>(i + kernel->getHeight() / 2);
				for (int j = -(kernel->getWidth()/2); j <= kernel->getWidth()/2; j++) {
					uchar* mat_col_ptr = mat_row_ptr + ((currentCol + j) * 3);
					float* kernel_col_ptr = kernel_row_ptr + ((j + kernel->getWidth()/2) * 3);
					sumb += mat_col_ptr[0] * kernel_col_ptr[0];
					sumg += mat_col_ptr[1] * kernel_col_ptr[1];
					sumr += mat_col_ptr[2] * kernel_col_ptr[2];
				}
			}
			sumb = sumb < 0 ? 0 : (sumb > 255 ? 255 : sumb);
			sumg = sumg < 0 ? 0 : (sumg > 255 ? 255 : sumg);
			sumr = sumr < 0 ? 0 : (sumr > 255 ? 255 : sumr);

			uchar* result_row_ptr = resultMat->ptr<uchar>(currentRow - startRow);
			uchar* result_col_ptr = result_row_ptr + ((currentCol - startCol) * 3);
			result_col_ptr[0] = (uchar)sumb;
			result_col_ptr[1] = (uchar)sumg;
			result_col_ptr[2] = (uchar)sumr;
		}
	}
	
	Image3* resultImage = new Image3(resultMat);
	return resultImage;
}