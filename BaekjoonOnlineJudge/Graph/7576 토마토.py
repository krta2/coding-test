# https://www.acmicpc.net/problem/7576

def is_all_done(box):
    for row in box:
        for tomato in row:
            if tomato == 0:
                return False
    return True


m, n = map(int, input().split())
box = []
edge_list = []
left_tomato = 0
for i in range(n):
    box.append(list(map(int, input().split())))
    for j in range(m):
        if box[i][j] == 1:
            edge_list.append((i, j))
        if box[i][j] == 0:
            left_tomato += 1

day = 0
while True:
    if left_tomato == 0:
        break

    if day > n * m:
        day = -1
        break

    day += 1
    new_edge_list = []
    for (x, y) in edge_list:
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for i in range(4):
            x_move = x + dx[i]
            y_move = y + dy[i]
            if 0 <= x_move < n and 0 <= y_move < m and box[x_move][y_move] == 0:
                new_edge_list.append((x_move, y_move))
                box[x_move][y_move] = 1
                left_tomato -= 1

    edge_list = new_edge_list

print(day)
