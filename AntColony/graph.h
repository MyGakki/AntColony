#pragma once
#include "constants.h"
#include "point.h"
#include <vector>
using namespace std;
typedef struct graph {
	vector<vector<float> > edge;											     //城市之间的边表
	vector<vector<float> > pheromone_table;				 //信息素浓度表
	int cityNum;
}graph;

//创建一个Graph
graph *createGraph(graph *G, std::vector<Point> ps);
