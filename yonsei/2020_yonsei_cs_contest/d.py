"""
N개의 정수로 이루어진 수열 a1, ... , aN이 있다. 택희는 해당 수열이 증가수열 혹은 감소수열이 되게 만들고 싶다.

증가수열은 모든 i(1 ≤ i < N)에 대해서 ai ≤ ai+1을 만족하는 수열이고, 감소수열은 ai ≥ ai+1을 만족하는 수열이다.

택희는 해당 수열의 맨 앞의 k개의 원소를 맨 뒤로 옮겨서 증가수열 또는 감소수열을 만들고 싶다. 즉, ak+1, ..., aN, a1, ..., ak가 증가수열,
또는 감소수열이 돼야 한다. 옮기지 않는 경우는 k=0이라고 하자. 이때, 적절한 k를 골라서 원하는 수열을 만들 수 있게 도와줘라.

입력
다음과 같이 입력이 주어진다.

N
a1 . . . aN
출력
증가수열, 또는 감소수열을 만들 수 있는 k를 출력하여라. 가능한 k가 여러 개면 가능한 가장 작은 k를 출력하여라.
만약에 그런 k가 존재하지 않는다면 -1을 출력하여라.

제한
1 ≤ N ≤ 1,000,000.
1 ≤ ai ≤ 1,000,000,000. (1 ≤ i ≤ N)
입력에 주어진 수들은 전부 정수다.

예제 입력 1
5
3 4 5 1 2

예제 출력 1
3

예제 입력 2
5
3 5 4 1 2

예제 출력 2
-1
"""


def main():
    n = int(input())
    numbers = [int(_) for _ in input().split()]

    k = -1

    if n <= 2:
        k = 0
    else:
        asc_fail = 0
        first_asc_fail = 0
        desc_fail = 0
        first_desc_fail = 0
        for i in range(1, n):
            # ascending check
            if numbers[i - 1] > numbers[i]:
                asc_fail += 1
                if asc_fail == 1:
                    first_asc_fail = i

            # descending check
            if numbers[i - 1] < numbers[i]:
                desc_fail += 1
                if desc_fail == 1:
                    first_desc_fail = i

        if asc_fail == 0 or desc_fail == 0:
            k = 0
        else:
            if asc_fail == 1 and numbers[0] >= numbers[n - 1]:
                k = first_asc_fail
            if desc_fail == 1 and numbers[0] <= numbers[n - 1]:
                if k != -1:
                    k = min(k, first_desc_fail)
                else:
                    k = first_desc_fail

    print(k)


if __name__ == '__main__':
    main()
