// https://www.acmicpc.net/problem/11726
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[1001];

	scanf("%d", &n);
	
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}