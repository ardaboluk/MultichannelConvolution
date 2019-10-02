#ifndef __KERNEL_H
#define __KERNEL_H

#include "image.h"

namespace conv {
	template <class T>
	class Kernel :public Image<T> {

	};
}

#endif