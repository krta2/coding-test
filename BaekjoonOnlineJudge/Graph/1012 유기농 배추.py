# https://www.acmicpc.net/problem/1012

n_t = int(input())

for t in range(n_t):
    m, n, k = map(int, input().split())

    land = [[0 for i in range(n)] for j in range(m)]

    grass_list = []
    for i in range(k):
        x, y = map(int, input().split())
        land[x][y] = 1
        grass_list.append((x, y))

    answer = 0
    for i in range(k):
        start_x, start_y = grass_list[i]
        if land[start_x][start_y]:
            answer += 1

            # Fill adjacency land (BFS)
            q = [(start_x, start_y)]
            land[start_x][start_y] = 0
            while q:
                x, y = q.pop(0)

                dx = [-1, 0, 1, 0]
                dy = [0, 1, 0, -1]
                for direction in range(4):
                    x_move = x + dx[direction]
                    y_move = y + dy[direction]
                    if 0 <= x_move < m and 0 <= y_move < n and land[x_move][y_move] == 1:
                        land[x_move][y_move] = 0
                        q.append((x_move, y_move))

    print(answer)
