# https://www.acmicpc.net/problem/9095

def recur(remaining):
    if remaining < 0:
        return 0
    if remaining == 0:
        return 1

    a = 0
    for i in range(1, 4):
        result = recur(remaining - i)
        if result:
            a += result

    return a


n = int(input())
for i in range(n):
    m = int(input())
    print(recur(m))
