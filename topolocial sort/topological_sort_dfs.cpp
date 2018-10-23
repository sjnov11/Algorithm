#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<bool> finished;
stack<int> topological_sort;
bool hasCycle;

void addEdge(int u, int v) {
	adj_list[u].push_back(v);
}

void DFS(int v) {
	visited[v] = true;
	for (auto next : adj_list[v]) {
		if (!visited[next])
			DFS(next);
		else if (!finished[next])
			hasCycle = true;
	}
	finished[v] = true;
	topological_sort.push(v);
	
}


int main() {
	int V = 7;
	adj_list.resize(V + 1);
	visited.resize(V + 1, false);
	finished.resize(V + 1, false);

	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(2, 5);
	addEdge(3, 5);
	addEdge(3, 6);
	addEdge(5, 7);
	addEdge(6, 2);

	for (int i = 1; i <= 7; i++) {
		if (!visited[i])
			DFS(i);
	}
	while (!topological_sort.empty()) {
		printf("%d ", topological_sort.top());
		topological_sort.pop();
	}
}