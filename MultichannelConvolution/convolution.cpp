
#include "convolution.h"

namespace conv {
	template <class T>
	Convolution<T>::Convolution(const Image<T> const& image, const Kernel<T> const& kernel) {
		this->image = image;
		this->kernel = kernel;
	}
}