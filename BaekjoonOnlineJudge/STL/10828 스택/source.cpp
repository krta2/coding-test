// https://www.acmicpc.net/problem/10828
// User ID: krta2
// Algorithm: STL

#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    int N;
    stack<int> st;
    
    scanf("%d", &N);

    for (int i=0; i < N;i++)
    {
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            int x;
            scanf("%d", &x);
            st.push(x);
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (st.empty() == true)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", st.top());
            st.pop();
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", st.size());
        }
        else if (strcmp(command, "empty") == 0)
        {
            if (st.empty() == true)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp(command, "top") == 0)
        {
            if (st.empty() == true)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", st.top());
        }
    }
    return 0;
}