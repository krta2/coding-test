# https://www.acmicpc.net/problem/11659

import sys


n, m = map(int, input().split())

n_list = [0] + list(map(int, sys.stdin.readline().split())) # sys.stdin.readline() 안 쓰면 시간 초과

for i in range(1, n + 1):
    n_list[i] += n_list[i - 1]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    print(n_list[b] - n_list[a - 1])
