#include "bits/stdc++.h"
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector< pair<int,int> > scores(N);
		for (int i=0; i<N; i++) 
			cin >> scores[i].first >> scores[i].second;

		sort(scores.begin(), scores.end());

		// Compare with std scorer in order
		int std = 0; int newbies = 1;
		for (int i=1; i<N; i++) {
			if (scores[std].second > scores[i].second) {
				std = i; newbies++;
			}
		}
	}
}
