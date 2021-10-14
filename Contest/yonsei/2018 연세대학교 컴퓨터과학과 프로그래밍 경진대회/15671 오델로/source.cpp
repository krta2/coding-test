// https://www.acmicpc.net/problem/2661
// User ID: krta2
// Algorithm: Brute Force

#include <stdio.h>

char board[7][7];
int N, turn, R, C;


bool valid(int tx, int ty)
{
	if (tx < 1 || ty < 1 || tx > 6 || ty > 6)
		return false;
	else
		return true;
}

bool the_end(int i, int tx, int ty) // tx, ty가 진행 방향(i)에 대한 가장자리인지 검사
{
	if (i == 0 && (tx == 1 || ty == 1))
		return true;
	else if (i == 1 && (tx == 1))
		return true;
	else if (i == 2 && (tx == 1 || ty == 6))
		return true;
	else if (i == 3 && (ty == 6))
		return true;
	else if (i == 4 && (tx == 6 || ty == 6))
		return true;
	else if (i == 5 && (tx == 6))
		return true;
	else if (i == 6 && (tx == 6 || ty == 1))
		return true;
	else if (i == 7 && (ty == 1))
		return true;
	else
		return false;
}

void change_board(int R, int C) // 놓인 돌에 따라 게임판을 바꾸는 함수
{
	// 8방향 정보
	int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
	int	dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

	int tx, ty; // 임시 좌표

	if (board[R][C] == 66) // 놓인 돌이 흑돌인 경우
	{
		for (int i = 0; i < 8; i++) // 8방향 검사
		{
			// 초기화
			int change_x[36] = { 0 };
			int change_y[36] = { 0 };
			int cnt = 0;
			bool flag = true;

			// 임시 좌표를 해당 방향으로 한 칸 이동한 상태로 초기화
			tx = R + dx[i];
			ty = C + dy[i];

			while (valid(tx, ty) == true) // 임시 좌표가 유효하면
			{
				if (board[tx][ty] == 46) // 진행하다 빈 칸을 만나면
				{
					flag = false;
					break;
				}
				else if (board[tx][ty] == 87) // 진행하다 흰 돌을 만나면
				{
					if ( the_end(i, tx, ty) == true ) // 진행 방향의 가장자리에 도달한 경우(못 뒤집음)
					{
						flag = false;
						break;
					}
					else // 뒤집어야 하는 목록에 추가
					{
						change_x[cnt] = tx;
						change_y[cnt] = ty;
						cnt++;
					}
				}
				else // 진행하다 검은 돌을 만나면
				{
					break;
				}

				// 다음 좌표로 임시좌표 이동
				tx += dx[i];
				ty += dy[i];
			}

			if (flag == true) // 뒤집을 수 있는 경우
			{
				for (int j = 0; j < cnt; j++) // 목록에 있는 돌 들을 뒤집는다
				{
					board[change_x[j]][change_y[j]] = 66;
				}
			}

		}

	}
	else // 놓인 돌이 백돌인 경우
	{
		for (int i = 0; i < 8; i++) // 8방향 검사
		{
			// 초기화
			int change_x[36] = { 0 };
			int change_y[36] = { 0 };
			int cnt = 0;
			bool flag = true;

			// 임시 좌표를 해당 방향으로 한 칸 이동한 상태로 초기화
			tx = R + dx[i];
			ty = C + dy[i];

			while (valid(tx, ty) == true) // 임시 좌표가 유효하면
			{
				if (board[tx][ty] == 46) // 진행하다 빈 칸을 만나면
				{
					flag = false;
					break;
				}
				else if (board[tx][ty] == 66) // 진행하다 흑 돌을 만나면
				{
					if (the_end(i, tx, ty) == true) // 진행 방향의 가장자리에 도달한 경우(못 뒤집음)
					{
						flag = false;
						break;
					}
					else // 뒤집어야 하는 목록에 추가
					{
						change_x[cnt] = tx;
						change_y[cnt] = ty;
						cnt++;
					}
				}
				else // 진행하다 흰 돌을 만나면
				{
					break;
				}

				// 다음 좌표로 임시좌표 이동
				tx += dx[i];
				ty += dy[i];
			}

			if (flag == true) // 뒤집을 수 있는 경우
			{
				for (int j = 0; j < cnt; j++) // 목록에 있는 돌 들을 뒤집는다
				{
					board[change_x[j]][change_y[j]] = 87;
				}
			}

		}
	}

}

int main()
{
	// 마지막 각 색의 돌 개수
	int num_b = 0;
	int num_w = 0;

	// 초기화
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			board[i][j] = 46;
	board[3][3] = board[4][4] = 87;
	board[3][4] = board[4][3] = 66;

	scanf("%d", &N);

	for (turn = 1; turn <= N; turn++)
	{
		scanf("%d %d", &R, &C);

		if (turn % 2 == 1) // 흑 차례
		{
			board[R][C] = 66;
			change_board(R, C);
		}
		else // 백 차례
		{
			board[R][C] = 87;
			change_board(R, C);
		}
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (board[i][j] == 66)
				num_b++;
			else if (board[i][j] == 87)
				num_w++;
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	if (num_b > num_w)
		printf("Black\n");
	else
		printf("White\n");

	return 0;
}

