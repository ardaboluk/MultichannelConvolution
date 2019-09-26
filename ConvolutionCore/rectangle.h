#pragma once

#include "point.h"

namespace conv {
	class Rectangle {
	private:
		Point p1, p2;
	public:
		Rectangle(Point, Point);
		Point getP1();
		Point getP2();
		int getArea();
	};
}