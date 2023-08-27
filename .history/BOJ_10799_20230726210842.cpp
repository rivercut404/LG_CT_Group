#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string brackets;
	cin >> brackets;

	stack<char> sticks;
	int len = brackets.length();
	int res = 0;

	for (int i=0; i<len; i++) {
		if (brackets[i] == '(')
			sticks.push('(');
		else if (brackets[i] == ')') {
			sticks.pop();
			if (brackets[i-1] == '(') {
				res += sticks.size();
			}
		}
	}

	cout << res;
}
