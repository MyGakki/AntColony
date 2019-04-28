#include "graph.h"
#include <iostream>
using namespace std;

graph *createGraph(graph *G, vector<Point> ps) {
	int i, j;
	for (i = 0; i <CITY_NUM; i++)
		for (j = i; j < CITY_NUM; j++) {
			float dis = ps[i].getDistance(ps[j]);
			G->edge[i][j] = G->edge[j][i] = dis;
		}
	return G;
}

void printGraph(graph G) {
	int i, j;
	for (i = 0; i < CITY_NUM; i++) {
		cout << endl;
		for (j = 0; j < CITY_NUM; j++)
			cout << G.edge[i][j];
	}
}