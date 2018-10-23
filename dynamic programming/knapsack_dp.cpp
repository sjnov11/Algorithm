#include <iostream>
using namespace std;


int dp[4][51];

int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int n = 3;
int W = 50;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int knapsack(int num, int weight) {
	if (num == 0 || weight == 0)
		return 0;
	if (wt[num - 1] > W)
		return knapsack(n - 1, weight);
	return max(knapsack(num - 1, weight), knapsack(num - 1, weight - wt[num- 1]) + val[num-1]);
}

int main() {
	//cout << knapsack(3, W) << endl;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if (j - wt[i] < 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
		}
	}
	cout << dp[n][W] << endl;
}