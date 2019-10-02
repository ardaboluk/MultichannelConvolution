#ifndef __RECTANGLE_H
#define __RECTANGLE_H

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

#endif