#pragma once
#include "constants.h"
#include "point.h"
#include <vector>
using namespace std;
typedef struct graph {
	vector<vector<float> > edge;											     //����֮��ı߱�
	vector<vector<float> > pheromone_table;				 //��Ϣ��Ũ�ȱ�
	int cityNum;
}graph;

//����һ��Graph
graph *createGraph(graph *G, std::vector<Point> ps);
