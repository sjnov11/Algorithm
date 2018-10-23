#include <iostream>
#include <vector>
using namespace std;

// Conquer 과정
void merge(vector<int>& nums, int l, int m, int r) {
	int idx = 0;
	int lcur = l, lend = m;
	int rcur = m + 1, rend = r;
	int size = r - l + 1;

	vector<int> temp(size);
	while (lcur <= lend && rcur <= rend) {
		if (nums[lcur] < nums[rcur]) temp[idx++] = nums[lcur++];
		else temp[idx++] = nums[rcur++];
	}
	while (lcur <= lend) {
		temp[idx++] = nums[lcur++];
	}
	while (rcur <= rend) {
		temp[idx++] = nums[rcur++];
	}

	for (int i = 0; i < size; i++) {
		nums[l + i] = temp[i];
	}
}

// Divide 과정
void mergeSort(vector<int>& nums, int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	mergeSort(nums, l, m);
	mergeSort(nums, m + 1, r);
	merge(nums, l, m, r);
}

int main() {
	vector<int> nums(6);
	nums = { 12, 11, 13, 13, 6, 7 };
	mergeSort(nums, 0, 5);
	for (auto num : nums) {
		printf("%d ", num);
	}
	printf("\n");

}