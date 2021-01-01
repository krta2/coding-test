// https://www.acmicpc.net/problem/1931
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
#include <algorithm>
using namespace std;

struct Lecture {
	int start;
	int end;
};

bool cmp(Lecture a, Lecture b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main() {
	int n, lastEnd, ans = 0;
	Lecture arr[100000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}

	sort(arr, arr + n, cmp);

	lastEnd = arr[0].end;
	ans++;
	for (int i = 1; i < n; i++) {
		if (arr[i].start >= lastEnd) {
			lastEnd = arr[i].end;
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}