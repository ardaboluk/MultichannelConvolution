#ifndef __POINT_H
#define __POINT_H

namespace conv {
	class Point {
	private:
		int x, y;
	public:
		Point(int x, int y);
		int getX();
		int getY();
	};
}

#endif