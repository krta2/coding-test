// https://www.acmicpc.net/problem/11279
// User ID: krta2
// Algorithm: STL

#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int N;
    priority_queue<int> pq;
    
    scanf("%d", &N);

    for (int i=0; i < N;i++)
    {
        int x;
        scanf("%d", &x);

        if (x==0)
        {
            if (pq.empty() == true)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
    return 0;
}