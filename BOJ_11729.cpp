#include "bits/stdc++.h"
using namespace std;

void hanoi(int n, int from, int to) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
	}
	else {
		int median = 6 - from - to;
		hanoi(n-1, from, median);
		cout << from << ' ' << to << '\n';
		hanoi(n-1, median, to);
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

    int mov[21]; mov[1] = 1;
	for (int i=2; i<21; i++) {
		mov[i] = 2*mov[i-1] + 1;
	}

	cout << mov[n] << '\n';
    hanoi(n, 1, 3);
}
