#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, cnt = 0;

	scanf("%d", &N);

	for (int i = 2; i <= N; i=i+2) // ÅÃÈñ »çÅÁ ¼ö
	{
		for (int j = 1; j <= N; j++) // ¿µÈÆ »çÅÁ ¼ö
		{
			if (i + j > N)
				break;
			for (int k = j + 2; k <= N; k++)
			{
				if (i + j + k > N)
					break;
				if (i + j + k == N)
				{
					cnt++;
					break;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}