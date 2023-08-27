#include "bits/stdc++.h"
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> numbers(N, 0);
	for (int i=0; i<N; i++)
	    cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	if (numbers[0] != 1) {
		cout << 1; return 0;
	}

	int sum = 1; int i = 1;

	while (numbers[i] <= sum+1 && i<N) {
    	sum += numbers[i];
		i++;
	}

	cout << sum+1;
}
