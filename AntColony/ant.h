#pragma once
#include "graph.h"
#include <vector>
//���̶�
int wheelSelection(vector<float> city);

//��һ�����ܵ���ĳ���
int selectNextCity(graph G, std::vector<int>,int now);

//������Ϣ��
void updatePheromone(graph *G, float length[], vector<vector<int> > route);