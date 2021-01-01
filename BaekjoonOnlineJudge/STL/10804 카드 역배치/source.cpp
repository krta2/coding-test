// Problem: https://www.acmicpc.net/problem/10804
// Algorithm: STL
// User ID: krta2

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int card[21];
    const int cardNum = 20;
    const int setNum = 10;

    for (int i = 1; i <= cardNum; i++) {
        card[i] = i;
    }

    for (int i = 0; i < setNum; i++) {
        int first, last;

        scanf("%d %d", &first, &last);
        
        reverse(card + first, card + last + 1);
    }

    for (int i = 1; i <= cardNum; i++) {
        printf("%d ", card[i]);
    }

    return 0;
}