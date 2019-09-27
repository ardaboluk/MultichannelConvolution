#pragma once

#include "point.h"

namespace conv {
	class Rectangle {
	private:
		Point pLeftUpper, pRightLower;
	public:
		Rectangle(Point, Point);
		Point getPLeftUpper();
		Point getPRightLower();
		int getArea();
	};
}