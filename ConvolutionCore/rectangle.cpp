
#include "rectangle.h"
#include <cmath>

namespace conv {
	Rectangle::Rectangle(Point pLeftUpper, Point prightLower) : pLeftUpper(0,0), pRightLower(0,0) {
		this->pLeftUpper = pLeftUpper;
		this->pRightLower = pRightLower;
	}

	Point Rectangle::getPLeftUpper() {
		return this->pLeftUpper;
	}

	Point Rectangle::getPRightLower() {
		return this->pRightLower;
	}

	int Rectangle::getArea() {
		return abs(this->pRightLower.getX() - this->pLeftUpper.getX()) * abs(this->pRightLower.getY() - this->pLeftUpper.getY());
	}
}