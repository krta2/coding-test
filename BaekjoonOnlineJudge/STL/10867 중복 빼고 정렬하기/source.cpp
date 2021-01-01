// https://www.acmicpc.net/problem/10867
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int arr[2001] = {0};
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int t;

        scanf("%d", &t);
        if (t < 0) {
            arr[1000+abs(t)] = 1;
        }
        else {
            arr[t] = 1;
        }
    }

    for (int i = 2000; i > 1000; i--) {
        if (arr[i] != 0) {
            printf("%d ", -i + 1000);
        }
    }
    for (int i = 0; i <= 1000; i++) {
        if (arr[i] != 0) {
            printf("%d ", i);
        }
    }

    return 0;
}