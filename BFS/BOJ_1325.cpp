#include "bits/stdc++.h"
using namespace std;

vector<int> temp;

void arr_or(vector<int>& arr, int N) {
    for (int i=0; i<N; i++) {
	    temp[i] = (arr[i]+temp[i] == 0) ? 0 : 1;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N, M;
	vector<int> hacks;
	int max_h = 0;

	cin >> N >> M;
	for (int i=0; i<N; i++)
		temp.push_back(0);
	vector< vector<int> > adj(N, temp);

	while (M--) {
	    // let X:from, Y:to 
		int x, y;
		cin >> y >> x;
		adj[x-1][y-1] = 1;
	}
    for (int i=0; i<N; i++) {
	    arr_or(adj[i], N);
        for (int j=0; j<N; j++) {
		    if (adj[i][j] == 1)
		        arr_or(adj[j], N);
		}

        // for (int j=0; j<N; j++)
		//     cout << temp[j] << ' ';
		// cout << '\n';

		int sum = 0;
        for (int j=0; j<N; j++)
		    sum += temp[j];

		if (sum == max_h) 
		    hacks.push_back(i);
		else if (sum > max_h) {
			max_h = sum;
		    hacks.clear();
			hacks.push_back(i);
		}
		temp.clear();
		for (int i=0; i<N; i++)
		    temp.push_back(0);
	}
	sort(hacks.begin(), hacks.end());
	for (auto n : hacks)
	    cout << (n+1) << ' ';
}
