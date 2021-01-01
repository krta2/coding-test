// https://www.acmicpc.net/problem/1946
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
#include <algorithm>
using namespace std;

struct Score {
	int document;
	int interview;
};

bool cmp(const Score a, const Score b) {
	return a.document < b.document;
}

int main() {
	int t, n;
	Score arr[100000];

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int ans, max;

		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &arr[j].document, &arr[j].interview);
		}

		sort(arr, arr + n, cmp);

		ans = 1;
		max = arr[0].interview;
		for (int j = 0; j < n; j++) {
			if (arr[j].interview < max) {
				ans++;
				max = arr[j].interview;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}