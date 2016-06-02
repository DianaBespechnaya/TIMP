#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
const unsigned int INF = 1000000;

bool* vis;
unsigned int* min_dist;
unsigned int** dist;
unsigned int E;
unsigned int start_E;

void Dijkstra(void){
	while (true){
		unsigned int min_d = INF, min_index = INF;

		bool isVisAll = true;
		for (unsigned int i = 0; i < E; i++){
			if (!vis[i]){
				isVisAll = false;
				if (min_dist[i] < min_d) {
					min_d = min_dist[i];
					min_index = i;
				}
			}
		}

		if (isVisAll){
			return;
		}
		vis[min_index] = true;

		for (unsigned int i = 0; i < E; i++){
			min_dist[i] = fmin(dist[min_index][i] + min_d, min_dist[i]);

		}


	}
}
int main(){
	unsigned int V, V1, V2, w;
	cin >> E >> V;
	cin >> start_E;

	vis = new bool[E];
	min_dist = new unsigned int[E];
	dist = new unsigned int*[E];

	for (unsigned int i = 0; i < E; i++){
		dist[i] = new unsigned int[E];
		min_dist[i] = INF;
		vis[i] = false;
		for (unsigned int j = 0; j < E; j++){
			dist[i][j] = INF;
		}
	}
	for (unsigned int i = 0; i < V; i++){
		cin >> V1 >> V2 >> w;
		dist[V1][V2] = w;
	}
	for (unsigned int i = 0; i < V; i++){
		min_dist[i] = dist[start_E][i];
		if (i == start_E){
			min_dist[i] = 0;
		}
	}

	Dijkstra();

	for (unsigned int i = 0; i < E; i++){
		cout << min_dist[i] << " ";
	}

	delete[] vis;
	delete[] min_dist;
	delete[] dist;
	return 0;
}