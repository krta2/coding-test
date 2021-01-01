// https://www.acmicpc.net/problem/11060
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[2000], jump;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i] = 9999;
	}

	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &jump);
		for (int j = 1; j <= jump; j++) {
			if (dp[i + j] > dp[i] + 1) {
				dp[i + j] = dp[i] + 1;
			}
		}
	}

	if (dp[n] == 9999) {
		printf("-1\n");
	}
	else {
		printf("%d\n", dp[n]);
	}

	return 0;
}