#ifndef __CONVOLUTION_H
#define __CONVOLUTION_H

#include "image.h"
#include "rectangle.h"

namespace conv {
	template <class T>
	class Convolution {
	public:
		virtual Image<T>* convolute(Rectangle) = 0;
	};
}

#endif