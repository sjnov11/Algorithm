#include <iostream>
#include <vector>

using namespace std;

// arr: 기존 배열 sequence
// node: 현재 트리 node의 idx
// start: 구간 시작점
// end : 구간 끝 점
long long buildSegmentTree(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		return buildSegmentTree(arr, tree, node * 2, start, (start + end) / 2) + buildSegmentTree(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long findRangeSum(vector<long long> &tree, int node, int left, int right, int start, int end) {
	if (right < start || end < left)
		return 0;
	if (left <= start && right >= end)
		return tree[node];
	return findRangeSum(tree, node * 2, left, right, start, (start + end) / 2) + findRangeSum(tree, node * 2 + 1, left, right, (start + end) / 2 + 1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (start < index || end < index)
		return;
	tree[node] += diff;
	// leaf 가 아닐 때 까지 반복
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, index, diff);
	}
}

int main() {

}
