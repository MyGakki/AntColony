#pragma once
class Point {
public:
	float x, y;
	Point(float x0, float y0) : x(x0), y(y0) {};
	float getDistance(Point);
};