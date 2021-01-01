// https://www.acmicpc.net/problem/1003
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

struct pibo {
	int zero;
	int one;
};

int main() {
	int t, n;
	pibo arr[41] = { 0 };

	arr[0].zero = 1;
	arr[0].one = 0;
	arr[1].zero = 0;
	arr[1].one = 1;
	for (int i = 2; i <= 40; i++) {
		arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
		arr[i].one = arr[i - 1].one + arr[i - 2].one;
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d %d\n", arr[n].zero, arr[n].one);
	}

	return 0;
}