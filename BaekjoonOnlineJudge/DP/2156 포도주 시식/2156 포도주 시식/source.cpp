// https://www.acmicpc.net/problem/2156
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, wine[10001], dp[10001] = { 0 }, ans = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
		if (i == 1) {
			dp[i] = wine[i];
		}
		else if (i == 2) {
			dp[i] = wine[i] + wine[i - 1];
		}
		else {
			if (dp[i - 3] + wine[i - 1] + wine[i] > dp[i - 2] + wine[i]) {
				dp[i] = dp[i - 3] + wine[i - 1] + wine[i];
			}
			else {
				dp[i] = dp[i - 2] + wine[i];
			}
		}

		if (dp[i - 1] > dp[i]) {
			dp[i] = dp[i - 1];
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}