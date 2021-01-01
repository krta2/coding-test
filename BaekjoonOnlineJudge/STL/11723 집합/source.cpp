// https://www.acmicpc.net/problem/11723
// User ID: krta2
// Algorithm: STL

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int N, x;
    int S[21] = {0};
    char command[100];
    
    scanf("%d", &N);

    for (int i=0; i < N;i++) {
        scanf("%s", &command);
        if (strcmp(command, "add") == 0) {
            scanf("%d", &x);
            S[x] = 1;
        }
        else if (strcmp(command, "remove") == 0) {
            scanf("%d", &x);
            S[x] = 0;
        }
        else if (strcmp(command, "check") == 0) {
            scanf("%d", &x);
            if (S[x]) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (strcmp(command, "toggle") == 0) {
            scanf("%d", &x);
            if (S[x]) {
                S[x] = 0;
            }
            else {
                S[x] = 1;
            }
        }
        else if (strcmp(command, "all") == 0) {
            fill_n(S, 21, 1);
        }
        else {
            fill_n(S, 21, 0);
        }
    }
    return 0;
}