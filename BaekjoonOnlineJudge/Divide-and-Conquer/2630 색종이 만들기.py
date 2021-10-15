# https://www.acmicpc.net/problem/2630

n = int(input())

paper = [[] for i in range(n)]

for i in range(n):
    colors = map(int, input().split())
    paper[i] += colors


def cutting(top, bottom, left, right):
    if top > bottom or left > right:
        return 0, 0

    blue_flag = True
    white_flag = True
    for i in range(top, bottom + 1):
        for j in range(left, right + 1):
            if paper[i][j] == 0:
                blue_flag = False
            else:
                white_flag = False

    if blue_flag:
        return 1, 0
    elif white_flag:
        return 0, 1
    else:
        height_mid = (top + bottom) // 2
        width_mid = (left + right) // 2

        lh_b, lh_w = cutting(top, height_mid, left, width_mid)
        rh_b, rh_w = cutting(top, height_mid, width_mid + 1, right)
        lb_b, lb_w = cutting(height_mid + 1, bottom, left, width_mid)
        rb_b, rb_w = cutting(height_mid + 1, bottom, width_mid + 1, right)

        return lh_b + rh_b + lb_b + rb_b, lh_w + rh_w + lb_w + rb_w


blue, white = cutting(0, n - 1, 0, n - 1)

print(white)
print(blue)

