#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[1001];
int V;

vector<int> dijkstra(int start) {
	vector<int> dist(V, 999999);
	vector<bool> visited(V, false);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first * (-1);
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] <= cost) continue;
		dist[cur] = cost;

		for (auto adj : adj_list[cur]) {
			if (visited[adj.first]) continue;
			int next = adj.first;
			int next_cost = cost + adj.second;
			
			pq.push(make_pair(next_cost*(-1), next));
		}
		visited[cur] = true;
	}
	return dist;
}


int main() {

}