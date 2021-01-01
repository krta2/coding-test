// https://www.acmicpc.net/problem/9465
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int n, dp[2][100001], sticker[2][100001];

int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int t = 0; t < testCase; t++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &sticker[i][j]);
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++) {
			if (dp[1][i - 1] > dp[1][i - 2]) {
				dp[0][i] = dp[1][i - 1] + sticker[0][i];
			}
			else {
				dp[0][i] = dp[1][i - 2] + sticker[0][i];
			}

			if (dp[0][i - 1] > dp[0][i - 2]) {
				dp[1][i] = dp[0][i - 1] + sticker[1][i];
			}
			else {
				dp[1][i] = dp[0][i - 2] + sticker[1][i];
			}
		}

		if (dp[0][n] > dp[1][n]) {
			printf("%d\n", dp[0][n]);
		}
		else {
			printf("%d\n", dp[1][n]);
		}
	}

	return 0;
}