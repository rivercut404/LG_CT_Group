#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	// Get the values of coin in descending order
	for (int i=N-1; i>=0; i--)
		cin >> coins[i];
	
	int ans = 0;
	for (int coin : coins) {
		ans += (int)(K/coin);
		K = K % coin;
		if (K == 0) break;
	}

	cout << ans;
}
