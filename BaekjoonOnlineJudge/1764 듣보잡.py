# https://www.acmicpc.net/problem/1764

n, m = map(int, input().split())

not_seen = []
not_heard = []

for i in range(n):
    name = input()
    not_seen.append(name)

for i in range(m):
    name = input()
    not_heard.append(name)

not_seen_heard = list(set(not_seen) & set(not_heard))
not_seen_heard.sort()

print(len(not_seen_heard))
for name in not_seen_heard:
    print(name)
