// https://www.acmicpc.net/problem/15678
// User ID: krta2
// Algorithm: DP

#include <stdio.h>

int main()
{
	int N, D;
	int stone[100001];
	int ans[100001];

	scanf("%d %d", &N, &D);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &stone[i]);
	}

	ans[1] = stone[1];
	int real_max = ans[1];
	int max;

	for (int i = 2; i <= N; i++)
	{
		max = stone[i];

		for (int j = i - 1; j >= i - D; j--)
		{
			if (j <= 0)
				break;
			if (max < ans[j] + stone[i])
				max = ans[j] + stone[i];
		}

		ans[i] = max;
		if (ans[i] > real_max)
			real_max = ans[i];
	}

	printf("%d\n", real_max);

	return 0;
}