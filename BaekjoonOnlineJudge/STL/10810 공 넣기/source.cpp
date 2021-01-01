// https://www.acmicpc.net/problem/10810
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int basket[101] = {0};
    
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int a, b, k;

        scanf("%d %d %d", &a, &b, &k);

        for (int j = a; j <= b; j++) {
            basket[j] = k;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}