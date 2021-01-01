#include <stdio.h>

int main()
{
	int N, k[1000] = { 0 };
	int M, p, q;
	int lecture[1000][51] = { 0 }; // 강의 정보 배열
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &k[i]);
		
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%d", &lecture[i][j]);
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int student[51] = { 0 }; // 학생 정보 배열
		int cnt = 0;

		scanf("%d", &p);

		for (int j = 0; j < p; j++)
		{
			scanf("%d", &q);
			student[q] = 1;
		}

		for (int j = 0; j < N; j++)
		{
			int flag = 1;
			for (int t = 0; t < k[j]; t++)
			{
				if (student[lecture[j][t]] == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}