#include "bits/stdc++.h"
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C, N;
	vector<int> V;
	vector<int> H;

	cin >> C >> R >> N;
    while (N--) {
        int temp, v, h;
		cin >> temp;
		if (temp) {
			cin >> v;
			V.push_back(v);
		}
		else {
    		cin >> h;
			H.push_back(h);
		}   
	}

	sort(V.begin(), V.end()); V.push_back(C);
	sort(H.begin(), H.end()); H.push_back(R);

	int max_v = 0;
	int max_h = 0;

	for (int i=1; i<V.size(); i++) {
    	if (V[i]-V[i-1] > max_v) max_v = V[i] - V[i-1];
	}
    for (int i=1; i<H.size(); i++) {
    	if (H[i]-H[i-1] > max_h) max_h = H[i] - H[i-1];
	}

	if (V.size() == 1) max_v = C;
	if (H.size() == 1) max_h = H;

	cout << (max_v*max_h) << '\n';
}
