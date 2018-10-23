#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
vector<int> indegree;
queue<int> q;
vector<int> result;

void addEdge(int u, int v) {
	adj_list[u].push_back(v);
	indegree[v]++;
}

bool topologicalSort(int V) {
	for (int v = 1; v <= V; v++) {
		if (indegree[v] == 0)
			q.push(v);
	}

	for (int i = 0; i < V; i++) {
		if (q.empty()) {
			printf("has Cycle\n");
			return false;
		}
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (auto adj : adj_list[cur]) {
			indegree[adj]--;
			if (indegree[adj] == 0) {
				q.push(adj);
			}
		}		
	}
	return true;
}


int main() {
	int V = 12;
	adj_list.resize(V + 1);
	indegree.resize(V + 1);
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 3);
	addEdge(2, 6);
	addEdge(2, 9);
	addEdge(3, 7);
	addEdge(5, 8);
	addEdge(6, 5);
	addEdge(6, 7);
	addEdge(7, 10);
	addEdge(7, 11);
	addEdge(9, 12);
	addEdge(10, 12);

	if (topologicalSort(V)) {
		for (auto n : result) {
			printf("%d ", n);
		}
		printf("\n");
	}
}