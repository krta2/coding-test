// https://www.acmicpc.net/problem/10811
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
        int a, b, t;

        scanf("%d %d", &a, &b);

        while (a < b) {
            t = basket[a];
            basket[a] = basket[b];
            basket[b] = t;

            a++;
            b--;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}