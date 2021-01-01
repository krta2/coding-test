// Problem: https://www.acmicpc.net/problem/10974
// Algorithm: STL
// User ID: krta2

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[10];

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (next_permutation(arr + 1, arr + n + 1)) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}