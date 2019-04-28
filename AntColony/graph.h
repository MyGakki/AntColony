#pragma once
#include "constants.h"
#include "point.h"
#include <vector>
typedef struct graph {
	float edge[CITY_NUM][CITY_NUM];											     //����֮��ı߱�
	float pheromone_table[CITY_NUM][CITY_NUM] = { 0 };				 //��Ϣ��Ũ�ȱ�
}graph;

//����һ��Graph
graph *createGraph(graph *G, std::vector<Point> ps);

//��ӡһ��Graph
void printGraph(graph G);
