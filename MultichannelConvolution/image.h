#pragma once

#include "data.h"

namespace conv {
	template <class T>
	class Image {

	public:
		virtual int getWidth() = 0;
		virtual int getHeight() = 0;
		virtual int getDepth() = 0;
		virtual Data<T> getData() = 0;
		virtual void setWidth(int) = 0;
		virtual void setHeight(int) = 0;
		virtual void setDepth(int) = 0;
		virtual void setData(Data<T>&) = 0;
	};
}