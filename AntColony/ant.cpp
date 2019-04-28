#include "ant.h"
#include<cmath>

bool contains(std::vector<int> allow, int j) {
	for (int i : allow) {
		if (i == j)
			return true;
	}
	return false;
}

int minInArray(float a[]) {
	int min = a[0],index =0;
	for (int i = 0; i < ANT_NUM; i++) {
		if (a[i] < min) {
			min = a[i];
			index = i;
		}
	}
	return index;
}

int wheelSelection(vector<float> city) {
	float number = 0.0, order;
	int i;
	do {
		number = rand() / (RAND_MAX + 1.0);
	} while(number == 0.0);

	order = 0.0;
	for (i = 0; i < city.size(); i++) {
		if (number > order && number <= order + city[i])
			return i;
		order += city[i];
	}
}

int selectNextCity(graph G,std::vector<int> allow, int now) {
	int j, selected, i;
	vector<float> next_city_probability(G.cityNum, 0.0f);
	for (j = 0; j < G.cityNum; j++) {
		if (contains(allow, j)) {
			float a = pow(G.pheromone_table[now][j], ALPHA);
			float b = pow(FACTOR / (float)G.edge[now][j], BETA);
			next_city_probability[j] = a + b;
		}
		else
			next_city_probability[j] = 0;
	}
	float all = 0;
	for (j = 0; j < G.cityNum; j++) {
		all += next_city_probability[j];
	}
	for (j = 0; j < G.cityNum; j++) {
		next_city_probability[j] = next_city_probability[j] / all;
	}
	selected = wheelSelection(next_city_probability);
	return selected;
}

void updatePheromone(graph *G, float length[], vector<vector<int> > route) {
	int i, j, k, l;
	/*for (i = 0; i < CITY_NUM + 1; i++) {
		for (j = 0; j < CITY_NUM + 1; j++) {
			if (G->edge[i][j] == 0) continue;
			weight = 0.0;
			for (k = 0; k < ANT_NUM; k++) {
				for (l = 0; l < CITY_NUM + 1; l++) {
					if (route[k][l] == i && route[k][l + 1] == j)
						weight += PHER_VALUE/length[k];
				}
			}
			G->pheromone_table[i][j] = G->pheromone_table[i][j] * (1 - EVAPORATION_RATE) + weight;
			
		}
	}*/
	for (i = 0; i < G->cityNum; i++) 
		for (j = 0; j < G->cityNum; j++)
			G->pheromone_table[i][j] = G->pheromone_table[i][j] * (1 - EVAPORATION_RATE);
	//for (k = 0; k < ANT_NUM; k++)
	//	for (l = 0; l < CITY_NUM - 1; l++)
	//		G->pheromone_table[route[k][l]][route[k][l + 1]] += PHER_VALUE / length[k];
	k = minInArray(length);
	for (l = 0; l < G->cityNum - 1; l++)
		G->pheromone_table[route[k][l]][route[k][l + 1]] += PHER_VALUE / length[k];
}