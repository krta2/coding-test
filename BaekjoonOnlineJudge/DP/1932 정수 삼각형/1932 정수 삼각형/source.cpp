// https://www.acmicpc.net/problem/1932
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int triangle[550][550], dp[550][550];

int main() {
	int n, ans = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	dp[1][1] = triangle[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i + 1][j] < dp[i][j] + triangle[i + 1][j]) {
				dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
			}
			if (dp[i + 1][j + 1] < dp[i][j] + triangle[i + 1][j + 1]) {
				dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
			}

			if (i == n) {
				if (dp[i][j] > ans) {
					ans = dp[i][j];
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}