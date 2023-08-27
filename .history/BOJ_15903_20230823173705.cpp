#include "bits/stdc++.h"
using namespace std;

int n, m;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	deque<int> cards(n);
	for (int i=0; i<n; i++) cin >> cards[i];
	sort(cards.begin(), cards.end());

	while (m--) {
		int x = cards.front(); cards.pop_front();
		int y = cards.front(); cards.pop_front();
		int sum = x+y;

		for (int i=0; i<n-2; i++) {
			if (cards[i] >= sum) 
				cards.insert(cards.begin()+i, 2, sum);
		}

		if (cards.size() == n-2) cards.insert(cards.end(), 2, sum);
	}
	
	int ans = 0;
	for (auto card : cards) ans += card;

	cout << ans << '\n';
}
