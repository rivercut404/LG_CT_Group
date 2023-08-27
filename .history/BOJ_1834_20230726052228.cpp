#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int answer = 0;

	for (int i=1; i<N; i++) {
		answer += (i*N + i);
	}

	cout << answer;
}
