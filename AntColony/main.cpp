#include <iostream>
#include <fstream>
#include "point.h"
#include "TSP.h"
using namespace std;
void main() {
	ifstream fin;
	fin.open("Text.txt");
	if (!fin.is_open()) {
		cout << "´ò¿ªÊ§°Ü£¡";
		exit(-1);
	}
	vector<Point> points;
	int index;
	float x, y;
	fin >> index >> x >> y;
	while (true) {
		points.push_back(Point(x, y));
		fin >> index >> x >> y;
		if (index == 0)
			break;
	}
	fin.close();
	graph G;
	createGraph(&G, points);
	TSPSolution(&G);
	getchar();
}