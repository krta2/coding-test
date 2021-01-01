// https://www.acmicpc.net/problem/2580
// User ID: krta2
// Algorithm: Backtracking

#include <cstdio>
#include <algorithm>
using namespace std;

int board[9][9];
bool solved = false;

void solve(int remain) {
	int px, py, num[10];

	if (remain == 0 && solved == false) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		solved = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		num[i] = 1;
	}

	px = py = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				px = i;
				py = j;
				break;
			}
		}
		if (px != -1) {
			break;
		}
	}

	// 가로줄 체크
	for (int i = 0; i < 9; i++) {
		if (num[board[px][i]] == 1) {
			num[board[px][i]] = 0;
		}
	}
	// 세로줄 체크
	for (int i = 0; i < 9; i++) {
		if (num[board[i][py]] == 1) {
			num[board[i][py]] = 0;
		}
	}
	// 3x3 체크
	for (int i = 3 * (int)(px / 3); i <= 3 * (int)(px / 3) + 2; i++) {
		for (int j = 3 * (int)(py / 3); j <= 3 * (int)(py / 3) + 2; j++) {
			if (num[board[i][j]] == 1) {
				num[board[i][j]] = 0;
			}
		}
	}

	// 칸 채우고 다음으로
	for (int i = 1; i <= 9; i++) {
		if (num[i] == 1) {
			board[px][py] = i;
			solve(remain - 1);
			board[px][py] = 0;
		}
	}
}

int main() {
	int remain = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) {
				remain++;
			}
		}
	}

	solve(remain);

	return 0;
}