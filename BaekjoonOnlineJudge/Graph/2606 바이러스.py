# https://www.acmicpc.net/problem/2606

n = int(input())
link = [[] for _ in range(n + 1)]

m = int(input())

for i in range(m):
    a, b = map(int, input().split())
    link[a].append(b)
    link[b].append(a)

visited = [True if i == 1 else False for i in range(n + 1)]
answer = 0
q = [1]
while q:
    computer = q.pop(0)
    answer += 1
    for neighbour in link[computer]:
        if not visited[neighbour]:
            q.append(neighbour)
            visited[neighbour] = True

print(answer - 1)
