// https://www.acmicpc.net/problem/1049
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m, a, b, package = 1000, single = 1000, ans = 100000;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a < package) {
			package = a;
		}
		if (b < single) {
			single = b;
		}
	}

	if (n % 6 == 0) {
		if (package * (n / 6) < ans) {
			ans = package * (n / 6);
		}
		if (single * n < ans) {
			ans = single * n;
		}
	}
	else {
		if (package * (n / 6 + 1) < ans) {
			ans = package * (n / 6 + 1);
		}
		if (package * (n / 6) + single * (n % 6) < ans) {
			ans = package * (n / 6) + single * (n % 6);
		}
		if (single * n < ans) {
			ans = single * n;
		}
	}

	printf("%d\n", ans);

	return 0;
}