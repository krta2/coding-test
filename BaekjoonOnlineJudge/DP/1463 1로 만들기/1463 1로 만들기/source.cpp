// https://www.acmicpc.net/problem/1463
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

int ans[1000001];

int main() {
	int n;

	scanf("%d", &n);

	ans[1] = 0;
	ans[2] = 1;
	ans[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			if (ans[i / 3] > ans[i / 2]) {
				ans[i] = ans[i / 2] + 1;
			}
			else {
				ans[i] = ans[i / 3] + 1;
			}
		}
		else if (i % 3 == 0) {
			if (ans[i / 3] > ans[i - 1]) {
				ans[i] = ans[i - 1] + 1;
			}
			else {
				ans[i] = ans[i / 3] + 1;
			}
		}
		else if (i % 2 == 0) {
			if (ans[i / 2] > ans[i - 1]) {
				ans[i] = ans[i - 1] + 1;
			}
			else {
				ans[i] = ans[i / 2] + 1;
			}
		}
		else {
			ans[i] = ans[i - 1] + 1;
		}
	}

	printf("%d\n", ans[n]);

	return 0;
}