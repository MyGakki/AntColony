#include "graph.h"
#include <iostream>
using namespace std;

graph *createGraph(graph *G, vector<Point> ps) {
	int i, j;
	G->cityNum = ps.size();
	for (i = 0; i < ps.size(); i++) {
		vector<float> distances;
		vector<float> phers;
		for (j = 0; j < ps.size(); j++) {
			distances.push_back(ps[i].getDistance(ps[j]));
			phers.push_back(0.0f);
		}
		G->edge.push_back(distances);
		G->pheromone_table.push_back(phers);
	}
	return G;
}