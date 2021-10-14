/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <deque>

using namespace std;

int Answer;

struct Node {
    int num;
    int connection;
};

bool cmp(const Node &a, const Node &b){
    return a.connection > b.connection;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        int n, m;
        int arr[100][100] = {0};
        Node node[100];
        deque<int> dq;
        int linearPosition[100] = {0};

        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            node[i].num = i;
            node[i].connection = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            arr[u][v] = 1;
            arr[v][u] = 1;
            node[u].connection++;
            node[v].connection++;
        }

        sort(node, node + n, cmp);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                dq.push_back(node[i].num);
            }
            else {
                dq.push_front(node[i].num);
            }
        }

        for (int i = 0; i < n; i++) {
            linearPosition[dq.front()] = i;
            dq.pop_front();
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i][j] == 1) {
                    Answer += abs(linearPosition[i] - linearPosition[j]);
                    arr[i][j] = 0;
                    arr[j][i] = 0;
                }
            }
        }

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}