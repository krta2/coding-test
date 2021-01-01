// https://www.acmicpc.net/problem/11047
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
using namespace std;

int main() {
	int n, k, a[10], ans = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > k) {
			continue;
		}
		else {
			ans += k / a[i];
			k = k % a[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}