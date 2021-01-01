// https://www.acmicpc.net/problem/10812
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int basket[101];

    for (int i = 1; i <= 100; i++) {
        basket[i] = i;
    }
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int first, last, middle;

        scanf("%d %d %d", &first, &last, &middle);
        
        rotate(&basket[first], &basket[middle], &basket[last + 1]);
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}