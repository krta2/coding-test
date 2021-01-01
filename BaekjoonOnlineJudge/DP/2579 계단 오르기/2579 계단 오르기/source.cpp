// https://www.acmicpc.net/problem/2579
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, stair[300], ans[300] = { 0 };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
		if (i == 1) {
			ans[i] = stair[i];
		}
		else if (i == 2) {
			ans[i] = stair[i] + stair[i - 1];
		}
		else {
			if (ans[i - 3] + stair[i - 1] + stair[i] > ans[i - 2] + stair[i]) {
				ans[i] = ans[i - 3] + stair[i - 1] + stair[i];
			}
			else {
				ans[i] = ans[i - 2] + stair[i];
			}
		}
	}

	printf("%d\n", ans[n]);

	return 0;
}