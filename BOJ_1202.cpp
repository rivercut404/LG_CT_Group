#include "bits/stdc++.h"
using namespace std;
#define weight first 
#define price second

bool compare(pair<int,int> A, pair<int,int> B) {
    return A.price > B.price;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector< pair<int,int> > jewels(N);
	for (int i=0; i<N; i++) {
	    cin >> jewels[i].weight >> jewels[i].price;
	}

	vector<int> cap(K);
	for (int i=0; i<K; i++) 
	    cin >> cap[i];
	
    sort(jewels.begin(), jewels.end(), compare);
	sort(cap.begin(), cap.end());
    
	int j = 0; long long max_v = 0;
	for (int i=0; i<K; i++) {
    	while (jewels[j].weight>cap[i] && j<N) {
			j++;
		}
		if (j == N) {
			j = 0;
			continue;
		}
		max_v += jewels[j].price;
		jewels[j].weight = 100000002;
		j = 0;
	}

	cout << max_v;
}
