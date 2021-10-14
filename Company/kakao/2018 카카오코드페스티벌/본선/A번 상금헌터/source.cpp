#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, a, b, contest[3][101];

	// 1회 콘테스트
	for (int i = 0; i <= 100; i++) {
		if (i == 1) {
			contest[1][i] = 5000000;
		}
		else if (2 <= i && i <= 3) {
			contest[1][i] = 3000000;
		}
		else if (4 <= i && i <= 6) {
			contest[1][i] = 2000000;
		}
		else if (7 <= i && i <= 10) {
			contest[1][i] = 500000;
		}
		else if (11 <= i && i <= 15) {
			contest[1][i] = 300000;
		}
		else if (16 <= i && i <= 21) {
			contest[1][i] = 100000;
		}
		else {
			contest[1][i] = 0;
		}
	}

	// 2회 콘테스트
	for (int i = 0; i <= 100; i++) {
		if (i == 1) {
			contest[2][i] = 5120000;
		}
		else if (2 <= i && i <= 3) {
			contest[2][i] = 2560000;
		}
		else if (4 <= i && i <= 7) {
			contest[2][i] = 1280000;
		}
		else if (8 <= i && i <= 15) {
			contest[2][i] = 640000;
		}
		else if (16 <= i && i <= 31) {
			contest[2][i] = 320000;
		}
		else {
			contest[2][i] = 0;
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", contest[1][a] + contest[2][b]);
	}

	return 0;
}