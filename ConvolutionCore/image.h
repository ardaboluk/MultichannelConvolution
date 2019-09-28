#pragma once

#include "datawrapper.h"

namespace conv {
	template <class T>
	class Image {
	public:
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual int getDepth() const = 0;
		virtual DataWrapper<T>* getDataWrapper() const = 0;
	};
}