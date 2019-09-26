
#include "rectangle.h"

namespace conv {
	Rectangle::Rectangle(Point p1, Point p2) : p1(0,0), p2(0,0) {
		this->p1 = p1;
		this->p2 = p2;
	}

	Point Rectangle::getP1() {
		return this->p1;
	}

	Point Rectangle::getP2() {
		return this->p2;
	}
}