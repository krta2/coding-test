// https://www.acmicpc.net/problem/4307
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, l, n, min, max;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &l, &n);
		min = 0;
		max = 0;
		for (int j = 0; j < n; j++) {
			int p;
			scanf("%d", &p);
			if (p <= l / 2) {
				if (p > min) {
					min = p;
				}
				if (l - p > max) {
					max = l - p;
				}
			}
			else {
				if (l - p > min) {
					min = l - p;
				}
				if (p > max) {
					max = p;
				}
			}
		}

		printf("%d %d\n", min, max);
	}

	return 0;
}