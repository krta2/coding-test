#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Data {
	int t;
	int p;
	int s;
};

struct Node {
	int score;
	int singerNum;
};

struct Singer {
	int songNum;
	int totalScore;
	int overTime = -1;
};

bool cmp(const Data a, const Data b) {
	return a.t < b.t;
}

int n, k, j;
vector<int> tree[200001];
Node node[200001];
Singer singer[200001];
Data dataSet[200001];

void fillSubtree(int time, int root, int S) {
	queue<int> q;
	int subtreeSize = 0, tempNode, tempSinger, bonus;

	// 먼저 본 서브 트리의 크기를 구한다.
	// BFS
	int visited[100001] = { 0 };
	q.push(root);
	while (!q.empty()) {
		tempNode = q.front();
		subtreeSize++;
		q.pop();
		for (int i = 0; i < tree[tempNode].size(); i++) {
			if (visited[tree[tempNode][i]] == 0) {
				visited[tree[tempNode][i]] = 1;
				q.push(tree[tempNode][i]);
			}
		}
	}

	// 서브 트리 내의 노드에 더해줘야 할 점수를 구한다.
	bonus = S / subtreeSize;

	// 서브 트리 내의 노드에 점수를 더해주며 동시에 가수에 대한 처리도 해준다.
	// BFS
	int visited2[100001] = { 0 };
	q.push(root);
	while (!q.empty()) {
		tempNode = q.front();
		tempSinger = node[tempNode].singerNum;
		singer[tempSinger].totalScore += bonus;
		if (singer[tempSinger].overTime == -1 && (double) singer[tempSinger].totalScore / (double) singer[tempSinger].songNum > (double) j) {
			singer[tempSinger].overTime = time;
		}
		q.pop();
		for (int i = 0; i < tree[tempNode].size(); i++) {
			if (visited2[tree[tempNode][i]] == 0) {
				visited2[tree[tempNode][i]] = 1;
				q.push(tree[tempNode][i]);
			}
		}
	}
}

int main() {
	int t;
	
	// 입력
	scanf("%d %d %d", &n, &k, &j);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &t);
		tree[t].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &node[i].singerNum);
		singer[node[i].singerNum].songNum++;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &dataSet[i].t, &dataSet[i].p, &dataSet[i].s);
	}

	// 데이터를 t의 오름차순으로 정렬
	sort(dataSet, dataSet + k, cmp);

	// 각 데이터 마다 처리
	for (int i = 0; i < k; i++) {
		fillSubtree(dataSet[i].t, dataSet[i].p, dataSet[i].s);
	}

	// 정답 출력
	for (int i = 1; i <= n; i++) {
		printf("%d\n", singer[node[i].singerNum].overTime);
	}

	return 0;
}