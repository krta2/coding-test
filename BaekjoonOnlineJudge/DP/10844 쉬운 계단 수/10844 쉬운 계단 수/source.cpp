// https://www.acmicpc.net/problem/10844
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[101][10], ans = 0;

	scanf("%d", &n);

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[n][i]) % 1000000000;
	}

	printf("%d\n", ans);

	return 0;
}