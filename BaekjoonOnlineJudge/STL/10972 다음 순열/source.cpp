// Problem: https://www.acmicpc.net/problem/10972
// Algorithm: STL
// User ID: krta2

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[10001], reverseIndex = -1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n; i >= 2; i--) {
        if (arr[i-1] < arr[i]) {
            reverseIndex = i - 1;
            break;
        }
    }

    if (reverseIndex == -1) {
        printf("%d", reverseIndex);
    }
    else {
        for (int i = n; i > reverseIndex; i--) {
            if (arr[reverseIndex] < arr[i]) {
                swap(arr[reverseIndex], arr[i]);
                sort(arr + reverseIndex + 1, arr + n + 1);
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}