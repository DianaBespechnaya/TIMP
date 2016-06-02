#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

bool* vis;
unsigned int* min;
unsigned int** dist;
unsigned int E, Ef;


void Dijkstra(void);

int main(){
	unsigned int v, e1, e2, w;
	cin >> E >> v;
	cin >> Ef;

	vis = new bool[E];
	min = new unsigned int[E];
	dist = new unsigned int*[E];

	for (unsigned int i = 0; i < E; i++){
		dist[i] = new unsigned int[E];
		min[i] = 1000000;
		vis[i] = false;
		for (unsigned int j = 0; j < E; j++){
			dist[i][j] = 1000000;
		}
	}
	for (unsigned int i = 0; i < v; i++){
		cin >> e1 >> e2 >> w;
		dist[e1][e2] = w;
	}
	for (unsigned int i = 0; i < v; i++){
		min[i] = dist[Ef][i];
		if (i == Ef){
			min[i] = 0;
		}
	}

	Dijkstra();

	for (unsigned int i = 0; i < E; i++){
		cout << min[i] << " ";
	}

	return 0;
}

void Dijkstra(void){
	while (true){

		unsigned int min_d = 1000000, min_index = 1000000;

		bool isVisAll = true;
		for (unsigned int i = 0; i < E; i++){
			if (!vis[i]){
				isVisAll = false;
				if (min[i] < min_d) {
					min_d = min[i];
					min_index = i;
				}
			}
		}

		if (isVisAll){
			return;
		}
		vis[min_index] = true;

		for (unsigned int i = 0; i < E; i++){
			min[i] = fmin(dist[min_index][i] + min_d, min[i]);

		}
	}
}