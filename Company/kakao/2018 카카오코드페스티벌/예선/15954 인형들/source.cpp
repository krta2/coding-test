// https://www.acmicpc.net/problem/15954
// User ID: krta2
// Algorithm: Math

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, k, doll[500];
	double m, v, ans = 9999999.0;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &doll[i]);
	}

	for (int t = 0; t + k - 1 < n; t++) {
		for (int i = t + k - 1; i < n; i++) {
			m = v = 0.0;

			for (int j = t; j <= i; j++) {
				m += (double)doll[j];
			}
			m /= (double) (i - t + 1);

			for (int j = t; j <= i; j++) {
				v += pow((double)doll[j] - m, 2.0);
			}
			v /= (double) (i - t + 1);

			if (sqrt(v) < ans) {
				ans = sqrt(v);
			}
		}
	}

	printf("%.11f\n", ans);

	return 0;
}