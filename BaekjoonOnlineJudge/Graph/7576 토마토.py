# https://www.acmicpc.net/problem/7576

# deque 을 이용한 풀이
from collections import deque


m, n = map(int, input().split())
box = []
q = deque()
for i in range(n):
    box.append(list(map(int, input().split())))
    for j in range(m):
        if box[i][j] == 1:
            q.append((i, j))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
while q:
    x, y = q.popleft()
    for i in range(4):
        x_move = x + dx[i]
        y_move = y + dy[i]
        if 0 <= x_move < n and 0 <= y_move < m and box[x_move][y_move] == 0:
            q.append((x_move, y_move))
            box[x_move][y_move] = box[x][y] + 1

max_day = 0
for row in box:
    if 0 in row:
        max_day = 0
        break

    if max(row) > max_day:
        max_day = max(row)

print(max_day - 1)

# list 를 이용한 풀이
# m, n = map(int, input().split())
# box = []
# edge_list = []
# left_tomato = 0
# for i in range(n):
#     box.append(list(map(int, input().split())))
#     for j in range(m):
#         if box[i][j] == 1:
#             edge_list.append((i, j))
#         if box[i][j] == 0:
#             left_tomato += 1
#
# day = 0
# dx = [-1, 0, 1, 0]
# dy = [0, 1, 0, -1]
# while True:
#     if left_tomato == 0:
#         break
#
#     if day > n * m:
#         day = -1
#         break
#
#     day += 1
#     new_edge_list = []
#     for (x, y) in edge_list:
#         for i in range(4):
#             x_move = x + dx[i]
#             y_move = y + dy[i]
#             if 0 <= x_move < n and 0 <= y_move < m and box[x_move][y_move] == 0:
#                 new_edge_list.append((x_move, y_move))
#                 box[x_move][y_move] = 1
#                 left_tomato -= 1
#
#     edge_list = new_edge_list
#
# print(day)
