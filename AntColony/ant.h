#pragma once
#include "graph.h"
#include <vector>
//���̶�
int wheelSelection(float city[]);

//��һ�����ܵ���ĳ���
int selectNextCity(graph G, std::vector<int>,int now);

//������Ϣ��
void updatePheromone(graph *G, float length[], int route[][CITY_NUM + 1]);