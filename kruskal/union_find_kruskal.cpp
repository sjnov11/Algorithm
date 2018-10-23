#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> parent;
vector<vector<int>> g;
vector<pair<int, int>> edge_list;

class Edge {
public:
	int src, dest, weight;

	Edge() {

	}
	Edge(int u, int v, int w) {
		this->src = u, this->dest = v, this->weight = w;
	}
};

//struct mycmp { 
//	bool operator() (Edge e1, Edge e2) {
//		return e1.weight > e2.weight;
//	}
//};

bool operator < (Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

class Graph {
public:
	int V, E;
	vector<Edge> edge;

	void init(int v, int e) {
		this->V = v;
		this->E = e;		
	}

	void addEdge(int u, int v, int w) {
		edge.push_back(Edge(u, v, w));
	}
};

// 부분 집합 구조체
class subset {
public:
	int parent; 
	int rank;
};
subset* sub_list;

int find(int elem) {
	if (sub_list[elem].parent == elem) return elem;
	return find(sub_list[elem].parent);
}

void uni(int elem1, int elem2) {
	int r1 = find(elem1);
	int r2 = find(elem2);

	if (sub_list[r1].rank < sub_list[r2].rank) {
		sub_list[r1].parent = r2;
	}
	else if (sub_list[r1].rank > sub_list[r2].rank) {
		sub_list[r2].parent = r1;
	}
	else {
		sub_list[r2].parent = r1;
		sub_list[r1].rank++;
	}
}

void kruskalMST(Graph* g) {
	vector<Edge> result;
	sort(g->edge.begin(), g->edge.end());
	int e = 0;
	int i = 0;

	sub_list = new subset[g->V];
	for (int v = 0; v < g->V; v++) {
		sub_list[v].parent = v;
		sub_list[v].rank = 0;
	}

	while (e < g->V - 1) {
		Edge cur = g->edge[i++];
		int u = cur.src;
		int v = cur.dest;
		if (find(u) == find(v)) continue;
		uni(u, v);
		result.push_back(cur);
		e++;
	}
	cout << "MST: \n";
	for (int i = 0; i < e; i++) {
		printf("%d -- % d == %d\n", result[i].src, result[i].dest, result[i].weight);
	}
}

int main() {
	Graph g;
	g.init(4, 5);

	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);

	kruskalMST(&g);
}