// https://www.acmicpc.net/problem/2661
// User ID: krta2
// Algorithm: Backtracking

#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int N;
bool solved = false;
string answer;

bool isGood() {
	int l = answer.length();

	for (int i = 1; i <= l / 2; i++) {
		if (answer.substr(l - i, i).compare(answer.substr(l - i * 2, i)) == 0) {
			return false;
		}
	}

	return true;
}

void solve() {
	if (!isGood()) {
		return;
	}
	if (answer.length() == N) {
		solved = true;
		printf("%s\n", answer.c_str());
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (!solved) {
			answer += to_string(i);
			solve();
			answer.pop_back();
		}
		else {
			return;
		}		
	}
}

int main() {
	scanf("%d", &N);

	solve();

	return 0;
}