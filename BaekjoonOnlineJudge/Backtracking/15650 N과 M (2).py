# https://www.acmicpc.net/problem/15650

def find(arr):
    if len(arr) == m:
        print(' '.join(arr))
        return

    if len(arr) > 0:
        last = int(arr[-1])
    else:
        last = 0

    for i in range(last + 1, n + 1):
        arr.append(str(i))
        find(arr)
        arr.pop()


n, m = map(int, input().split())

find([])
