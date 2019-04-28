#pragma once
#include "graph.h"
#include <vector>
//轮盘赌
int wheelSelection(vector<float> city);

//下一个可能到达的城市
int selectNextCity(graph G, std::vector<int>,int now);

//更新信息素
void updatePheromone(graph *G, float length[], vector<vector<int> > route);