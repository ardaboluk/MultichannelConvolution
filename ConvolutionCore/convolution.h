#pragma once

#include "image.h"
#include "kernel.h"
#include "rectangle.h"

namespace conv {
	template <class T>
	class Convolution {
	public:
		virtual Image<T>* convolute(Rectangle) const = 0;
	};
}