#pragma once
#include "constants.h"
#include "point.h"
#include <vector>
typedef struct graph {
	float edge[CITY_NUM][CITY_NUM];											     //城市之间的边表
	float pheromone_table[CITY_NUM][CITY_NUM] = { 0 };				 //信息素浓度表
}graph;

//创建一个Graph
graph *createGraph(graph *G, std::vector<Point> ps);

//打印一个Graph
void printGraph(graph G);
