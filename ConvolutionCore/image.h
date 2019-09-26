#pragma once

#include "data.h"

namespace conv {
	template <class T>
	class Image {
	public:
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual int getDepth() const = 0;
		virtual Data<T>* getData() const = 0;
	};
}