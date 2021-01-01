// https://www.acmicpc.net/problem/10845
// User ID: krta2
// Algorithm: STL

#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
    int N;
    queue<int> q;
    
    scanf("%d", &N);

    for (int i=0; i < N;i++)
    {
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (q.empty() == true)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.front());
            q.pop();
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", q.size());
        }
        else if (strcmp(command, "empty") == 0)
        {
            if (q.empty() == true)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(command, "front") == 0)
        {
            if (q.empty() == true)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.front());
        }
        else if(strcmp(command, "back") == 0)
        {
            if (q.empty() == true)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", q.back());
        }
    }
    return 0;
}