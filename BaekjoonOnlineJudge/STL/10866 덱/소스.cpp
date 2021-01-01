#include <deque>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, t;
	char command[100];
	deque<int> dq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> command;

		if (strcmp(command, "push_front") == 0)
		{
			cin >> t;
			dq.push_front(t);
			continue;
		}
		if (strcmp(command, "push_back") == 0)
		{
			cin >> t;
			dq.push_back(t);
			continue;
		}
		if (strcmp(command, "pop_front") == 0)
		{
			if (dq.empty() == true)
			{
				cout << -1 << "\n";
			}
			else
			{
				t = dq.front();
				dq.pop_front();
				cout << t << "\n";
			}
			continue;
		}
		if (strcmp(command, "pop_back") == 0)
		{
			if (dq.empty() == true)
			{
				cout << -1 << "\n";
			}
			else
			{
				t = dq.back();
				dq.pop_back();
				cout << t << "\n";
			}
			continue;
		}
		if (strcmp(command, "size") == 0)
		{
			t = dq.size();
			cout << t << "\n";
			continue;
		}
		if (strcmp(command, "empty") == 0)
		{
			t = dq.empty();
			cout << t << "\n";
			continue;
		}
		if (strcmp(command, "front") == 0)
		{
			if (dq.empty() == true)
			{
				cout << -1 << "\n";
			}
			else
			{
				t = dq.front();
				cout << t << "\n";
			}
		}
		if (strcmp(command, "back") == 0)
		{
			if (dq.empty() == true)
			{
				cout << -1 << "\n";
			}
			else
			{
				t = dq.back();
				cout << t << "\n";
			}
		}


	}

	return 0;
}