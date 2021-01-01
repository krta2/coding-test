// https://www.acmicpc.net/problem/11399
// User ID: krta2
// Algorithm: Greedy

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[1000], ans = 0, temp = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		temp += arr[i];
		ans += temp;
	}

	printf("%d\n", ans);

	return 0;
}