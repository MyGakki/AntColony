#include "TSP.h"
#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
void remove(vector<int> &vec, int n) {
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		if (*iter == n) {
			vec.erase(iter);
			break;
		}
	}
}

void TSPSolution(graph* G) {
	int i, j;
	srand((unsigned)time(0));
	for (i = 0; i < CITY_NUM; i++)
		for (j = i; j < CITY_NUM; j++)
			G->pheromone_table[j][i] = G->pheromone_table[i][j] = FAVOR;
	int route[ANT_NUM][CITY_NUM + 1];
	float length[ANT_NUM] = { 0 };
	int now, next;
	for (int count = 0; count < TOTAL_TURN; count++) {
		for (i = 0; i < ANT_NUM; i++)
			length[i] = 0;
		for (i = 0; i < ANT_NUM; i++) {
			vector<int> allow(CITY_NUM);
			for (j = 0; j < CITY_NUM; j++) {
				allow[j] = j;
				route[i][j] = -1;
			}
			::remove(allow, 0);
			now = next = 0;
			route[i][0] = 0;
			j = 1;
			while (allow.size() > 0) {
				next = selectNextCity(*G,allow, now);
				::remove(allow, next);
				route[i][j++] = next;
				length[i] += G->edge[now][next];
				now = next;
				allow.shrink_to_fit();
			}
			route[i][j] = 0;
			length[i] += G->edge[now][0];
		}
 		updatePheromone(G, length, route);
	}

	int r[17] = {1 ,14, 13, 12, 7, 6 ,15, 5, 11, 9, 10, 16, 3, 2, 4, 8, 1};
	float l = 0;
	cout << "1 -> ";
	for (i = 0; i < CITY_NUM; i++) {
		cout << r[i + 1] << "-> ";
		l += G->edge[r[i] - 1][r[i+1] - 1];
	}
	cout <<"shortest path length£º"<< l<<endl;
	for (i = 0; i < ANT_NUM; i++) {
		cout << "======length" << i << ":" << length[i]<<"======\n";
		for (j = 0; j < CITY_NUM + 1; j++) {
			if (route[i][j] == -1)
				break;
			else
				cout << "->";
			cout << route[i][j] + 1;
		}
		cout << endl;
	}
}

