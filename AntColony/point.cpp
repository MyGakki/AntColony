#include "point.h"
#include <cmath>
float Point::getDistance(Point p) {
	return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
}