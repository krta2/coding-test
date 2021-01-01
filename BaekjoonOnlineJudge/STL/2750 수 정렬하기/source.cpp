// https://www.acmicpc.net/problem/2750
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int N, x;
    priority_queue<int> pq;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        pq.push(-x);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", -pq.top());
        pq.pop();
    }
    return 0;
}