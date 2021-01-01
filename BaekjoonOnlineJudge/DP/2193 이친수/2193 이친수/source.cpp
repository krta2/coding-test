// https://www.acmicpc.net/problem/2193
// User ID: krta2
// Algorithm: DP

#include <cstdio>
#include <algorithm>
using namespace std;

long long int n, ans[90];

int main() {
	
	scanf("%d", &n);
	ans[1] = 1;
	ans[2] = 1;
	for (int i = 3; i <= n; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}

	printf("%lld\n", ans[n]);

	return 0;
}