// https://www.acmicpc.net/problem/15667
// User ID: krta2
// Algorithm: Math

#include <stdio.h>
using namespace std;

int main()
{
	int N, t, cnt, ans = 0;

	scanf("%d", &N);

	for (int k = 1; k <= 10101; k++)
	{
		cnt = 1 + k + k * k;
		if (cnt == N)
		{
			ans = k;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}