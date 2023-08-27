#include "bits/stdc++.h"
using namespace std;
#define days first
#define score second

bool compare(pair<int,int> A, pair<int,int> B) {
    return A.days < B.days;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	vector<int> count(1001, 0);
	vector< pair<int,int> > hws(N, make_pair(0, 0));
	for (int i=0; i<N; i++) {
		cin >> hws[i].days;
		cin >> hws[i].score;
		count[hws[i].days]++;
	}
    
	int max_day = 0;
	for (auto hw : hws) {
		if (hw.days > max_day) {
			max_day = hw.days;
		}
	}
	bool flag = false;
	for (int i=1; i<=max_day; i++) {
		if (!flag) {
			count[i] += count[i-1];
		    if (i < count[i]) {
				flag = true;
			}
		} else {
		    flag = false;
		}
	}

	for (int i=1; i<=max_day; i++) 
	    cout << count[i] << ' ';
}
