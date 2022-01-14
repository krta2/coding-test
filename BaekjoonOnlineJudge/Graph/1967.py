# https://www.acmicpc.net/problem/1967

from collections import deque, defaultdict


def bfs(distance, start_node):
    q = deque()
    q.append((start_node, 0))
    visited = set()
    visited.add(start_node)
    max_node = start_node
    max_d = 0
    while q:
        current_node, current_d = q.popleft()
        for target_node, d in distance[current_node].items():
            if target_node not in visited:
                visited.add(target_node)
                target_d = current_d + d
                q.append((target_node, target_d))
                if target_d > max_d:
                    max_node = target_node
                    max_d = target_d

    return max_node, max_d


n = int(input())

distance = defaultdict(dict)
for i in range(n - 1):
    start, end, d = list(map(int, input().split()))
    distance[start][end] = d
    distance[end][start] = d

end_node, _ = bfs(distance, 1)
_, radius = bfs(distance, end_node)

print(radius)
