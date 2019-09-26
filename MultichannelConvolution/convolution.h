#pragma once

#include "image.h"
#include "kernel.h"
#include "rectangle.h"

namespace conv {
	template <class T>
	class Convolution {
	private:
		Image<T>& image;
		Kernel<T>& kernel;
	public:
		Convolution(const Image<T> const&, const Kernel<T> const&);
		Image* convolute(const Rectangle);
	};
}