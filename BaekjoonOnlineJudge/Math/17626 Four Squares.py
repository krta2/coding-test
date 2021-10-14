# https://www.acmicpc.net/problem/17626

def find(remaining, depth, minimum):
    if remaining == 0:
        return depth

    if depth >= minimum - 1:
        return depth + 1

    a = int(remaining ** 0.5)
    while a > 0:
        remaining -= a ** 2

        result = find(remaining, depth + 1, minimum)
        if result < minimum:
            minimum = result

        remaining += a ** 2
        a -= 1

    return minimum


n = int(input())

print(find(n, 0, 4))
