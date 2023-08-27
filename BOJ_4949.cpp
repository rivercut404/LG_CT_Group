#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;
	do {
		getline(cin, line);
		int len = line.length();
		stack<char> S; 
		for (int i=0; i<len; i++) {
			if (line[i] == '(' || line[i] == '[') {
				S.push(line[i]);
			} else if (line[i] == ')' || line[i] == ']') {
				if (S.empty()) {
				    S.push(line[i]);
					break;
				}
				char br = (line[i] == ')') ? '(' : '[';
				if (S.top() == br) {
					S.pop();
				} else 
				    break;
			} else 
				continue;
		}
		if (S.empty()) 
		    cout << "yes";
		else
		    cout << "no";
	} while (line != ".");
}
