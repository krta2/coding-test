"""
안형찬 교수님은 알고리즘 분석 기말고사를 준비하려고 한다.

알고리즘 기말고사는 총 M분 동안 쉬는 시간 없이 볼 예정이며, 인원이 너무 많아서 공학관 C040호에서 말고 다른 강의실에서 시험을 치를 수 없게 되었다.

공학관 C040호는 0분부터 S분까지 사용 가능하다. S는 무조건 M 이상이기 때문에 안 교수님은 별문제 없이 시험을 치를 것으로 생각하였다. 그러나 공학과 C040호에는 다른 시험도 예정되어 있어서 겹치지 않는 시간을 잡아야 한다.

각 시험은 xi분에 시작해서 yi분 동안 진행하며 서로 겹치지 않는다. 한 시험이 끝난 직후 다음 시험이 있는 경우도 겹치지 않는 것으로 판단한다. 즉, xi + yi ≤ xj 일 때 i 시험과 j 시험은 서로 겹치지 않는다.

안형찬 교수님이 시험을 언제 치를 수 있는지 구해보자.

입력
다음과 같이 입력이 주어진다.

N M S
A1 B1
. . .
AN BN
출력
교수님이 시험을 시작할 수 있는 시각을 출력하여라. 시작 가능한 시각이 여러 개 있으면 그중 가장 앞선 시각을 출력한다. 시험을 치룰 수 없다면 -1을 출력하여라.

제한
1 ≤ N ≤ 100,000.
1 ≤ M ≤ S ≤ 1,000,000,000.
0 ≤ Ai < Ai + Bi ≤ S.
입력에 주어진 수들은 전부 정수다.

예제 입력 1
2 3 5
0 1
4 1

예제 출력 1
1

예제 입력 2
2 3 5
0 2
4 1

예제 출력 2
-1
"""

n, m, s = [int(_) for _ in input().split()]

schedules = []
for i in range(n):
    start, end = [int(_) for _ in input().split()]
    schedules.append((start, end))

schedules.sort(key=lambda x: x[0])

start_time = -1
prev_end = 0
for schedule in schedules:
    start, end = schedule
    if start - prev_end >= m:
        start_time = prev_end
        break

    prev_end = start + end

if start_time == -1 and s - prev_end >= m:
    start_time = prev_end

print(start_time)
