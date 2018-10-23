#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int partition(vector<int> &nums, int left, int right) {
	// �������� �ǹ��� ������� ����Ŀ� ���� �ٸ���.
	//int l = 0, r = nums.size() - 1;
	int i = left, j = right;
	int pivot = nums[i++];

	while (true) {		
		// ���������� �ǹ����� ū ���� ����
		while (i <= right && nums[i] <= pivot) {
			i++;
		}
		// ���������� �ǹ����� ���� ���� ����
		while (j >= left && nums[j] > pivot) {
			j--;
		}
		if (i >= j) break;
		swap(&nums[i], &nums[j]);
	} 
	swap(&nums[left], &nums[j]);
	return j;
}

void quickSort(vector<int> &nums, int l, int r) {
	if (l < r) {
		int m = partition(nums, l, r);
		quickSort(nums, l, m - 1);
		quickSort(nums, m + 1, r);
	}
}

int main() {
	vector<int> nums(7);
	nums = { 10, 80, 30, 30, 40, 50, 70 };
	quickSort(nums, 0, 6);

	for (auto num : nums) {
		printf("%d ", num);
	}
}