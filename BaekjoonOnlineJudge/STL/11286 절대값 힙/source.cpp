// https://www.acmicpc.net/problem/11286
// User ID: krta2
// Algorithm: STL

#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;

int main() {
    int N;
    priority_queue<pair<int,int>> pq;
    
    scanf("%d", &N);

    for (int i=0; i < N;i++) {
        int x;
        scanf("%d", &x);

        if (x==0) {
            if (pq.empty() == true) {
                printf("0\n");
            }
            else {
                printf("%d\n", -pq.top().second);
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(-abs(x), -x));
        }
    }
    return 0;
}