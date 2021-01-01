// https://www.acmicpc.net/problem/4883
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100002][4];

int main() {
	int n, cnt = 0, cost;

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		cnt++;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				dp[i][j] = 100000000;
			}
		}

		dp[1][2] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &cost);
				if (i == 1 && j == 1) {
					continue;
				}

				if (j == 1) {
					if (dp[i + 1][j] > dp[i][j] + cost) {
						dp[i + 1][j] = dp[i][j] + cost;
					}
					if (dp[i + 1][j + 1] > dp[i][j] + cost) {
						dp[i + 1][j + 1] = dp[i][j] + cost;
					}
					if (dp[i][j + 1] > dp[i][j] + cost) {
						dp[i][j + 1] = dp[i][j] + cost;
					}
				}
				else if (j == 2) {
					if (dp[i + 1][j - 1] > dp[i][j] + cost) {
						dp[i + 1][j - 1] = dp[i][j] + cost;
					}
					if (dp[i + 1][j] > dp[i][j] + cost) {
						dp[i + 1][j] = dp[i][j] + cost;
					}
					if (dp[i + 1][j + 1] > dp[i][j] + cost) {
						dp[i + 1][j + 1] = dp[i][j] + cost;
					}
					if (dp[i][j + 1] > dp[i][j] + cost) {
						dp[i][j + 1] = dp[i][j] + cost;
					}
				}
				else {
					if (dp[i + 1][j - 1] > dp[i][j] + cost) {
						dp[i + 1][j - 1] = dp[i][j] + cost;
					}
					if (dp[i + 1][j] > dp[i][j] + cost) {
						dp[i + 1][j] = dp[i][j] + cost;
					}
				}

				dp[i][j] += cost;
			}
		}

		printf("%d. %d\n", cnt, dp[n][2]);
	}
	
	return 0;
}