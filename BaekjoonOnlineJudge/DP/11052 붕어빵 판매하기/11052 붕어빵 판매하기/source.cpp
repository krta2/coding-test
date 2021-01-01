// https://www.acmicpc.net/problem/11052
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int set[1001], dp[1001];

int main() {
	int n, t;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &set[i]);
		for (int j = 1; j <= i; j++) {
			if (dp[i] < dp[i - j] + set[j]) {
				dp[i] = dp[i - j] + set[j];
			}
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}