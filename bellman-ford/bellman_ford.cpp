#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define V 5
#define INFINITY 999999
vector<pair<int, int>> adj_list[V+1];
int dist[V+1];

int bellman_ford(int s) {
	memset(dist, INFINITY, sizeof(int)*(V + 1));
	dist[s] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (int u = 1; u <= V; u++) {
			if (dist[u] == INFINITY) continue;
			for (auto edge : adj_list[u]) {
				int v = edge.first;
				int w = edge.second;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
				}
			}
		}
	}

	for (int u = 1; u <= V; u++) {
		if (dist[u] == INFINITY) continue;
		for (auto edge : adj_list[u]) {
			int v = edge.first;
			int w = edge.second;
			if (dist[v] > dist[u] + w) {
				cout << "Negative cycle detected!\n";
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	// A: 1 ~ E: 5

	adj_list[1].push_back(make_pair(2, -1));
	adj_list[1].push_back(make_pair(3, 4));
	adj_list[2].push_back(make_pair(3, 3));
	adj_list[2].push_back(make_pair(4, 2));
	adj_list[2].push_back(make_pair(5, 2));
	//adj_list[3].push_back(make_pair(1, -4));
	adj_list[4].push_back(make_pair(2, 1));
	adj_list[4].push_back(make_pair(3, 5));
	adj_list[5].push_back(make_pair(4, -3));

	int ret = bellman_ford(1);
	if (ret != 0) {
		for (int i = 1; i <= 5; i++) {
			cout << dist[i] << " ";
		}
		cout << "\n";
	};
	
	
}	