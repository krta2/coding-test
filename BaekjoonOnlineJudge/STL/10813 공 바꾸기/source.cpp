// https://www.acmicpc.net/problem/10813
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int basket[101];
    
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= 100; i++) {
        basket[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, t;

        scanf("%d %d", &a, &b);

        t = basket[a];
        basket[a] = basket[b];
        basket[b] = t;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}