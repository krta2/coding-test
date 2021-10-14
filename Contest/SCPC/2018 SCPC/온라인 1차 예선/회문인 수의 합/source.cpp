/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int Answer;

bool isPalindrome(int n) {
    string num;
    num = to_string(n);

    int l = num.length();
    for (int i = 0; i < l / 2; i++) {
        if (num.at(i) != num.at(l - 1 - i)) {
            return false;
        }
    }

    return true;
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
		int n;
        bool flag = false;
        vector<int> v;
        cin >> n;

        // Answer = 1
        if (isPalindrome(n)) {
            Answer = 1;
            v.push_back(n);
        }
        else {
            // Answer = 2
            for (int i = n; i >= n / 2; i--) {
                if (isPalindrome(i) && isPalindrome(n - i)) {
                    Answer = 2;
                    v.push_back(i);
                    v.push_back(n - i);
                    break;
                }
            }

            //Answer = 3
            if (Answer == 0) {
                for (int i = n; i >= n / 3; i--) {
                    if (!isPalindrome(i)) continue;
                    for (int j = n - i; j >= (n - i) / 2; j--) {
                        if (!isPalindrome(j)) continue;
                        if (isPalindrome(n - i - j)) {
                            Answer = 3;
                            v.push_back(i);
                            v.push_back(j);
                            v.push_back(n - i - j);
                            flag == true;
                            break;
                        }
                    }
                    if (flag == true) break;
                }
            }
        }

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer;
        for (int i = 0; i < Answer; i++) {
            cout << " " << v[i];
        }
        cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}