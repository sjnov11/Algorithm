#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[100];
bool visited[100];

int prim(int start) {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));

	int ret = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int cur_w = q.top().first;
		q.pop();

		if (visited[cur]) continue;
		visited[cur] = true;
		ret += cur_w*(-1);
		for (auto next : adj_list[cur]) {
			int v = next.first;
			int w = next.second;

			q.push(make_pair(w*(-1), v));
		}
	}
	return ret;
}

int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj_list[u].push_back(make_pair(v,w));
		adj_list[v].push_back(make_pair(u,w));
	}
	cout << prim(0) << endl;
}