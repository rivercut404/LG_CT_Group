#include "bits/stdc++.h"
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, oil, price;
	vector<int> dist;
	vector<int> prices;
	int fee = 0;
	cin >> N;
    
	for (int i=0; i<N-1; i++) {
        int temp;
		cin >> temp;
		dist.push_back(temp);
	}

	for (int i=0; i<N; i++) {
	    int price;
		cin >> price;
		prices.push_back(price);
	}

    oil = dist.front();
	price = prices.front();

	for (int i=1; i<N-1; i++) {
	    if (price <= prices[i]) {
		    oil += dist[i];
		} else {
		    fee += (oil*price);
			price = prices[i];
			oil = dist[i];
		}
	}
    fee += (oil*price);

	cout << fee;
}
