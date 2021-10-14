# https://www.acmicpc.net/problem/17219

n, m = map(int, input().split())

info = {}
for i in range(n):
    site, pw = input().split()
    info[site] = pw

for i in range(m):
    site = input()
    print(info[site])