#include "bits/stdc++.h"
using namespace std;

int T, N;
int value[1000001];
// bool is_desc = true;
vector <long long> profit;

int get_max_idx(int from, int to)
{
	int max_idx = from;
	for (int i = from+1; i < to; i++) {
	    if (value[max_idx] < value[i]) max_idx = i;
	}
	return max_idx;
}

int get_temp_profit(int from, int sell)
{
    // returns sum of the value[sell] - value[i] for i [from, sell-1)
	int sum = 0;
	for (int i=from; i<sell; i++) 
		sum += (value[sell] - value[i]);

	return sum;
}

bool is_desc(int from) 
{
	bool ret = false;
	for (int i=from; i<N-1; i++) {
		if (value[i] < value[i+1]) {
			ret = true;
			break;
		}
	}
	return ret;
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=0; i<N; i++)
			cin >> value[i];

		int from = 0;
		// Start iteration 
		while (from != N) {
			int max_idx = get_max_idx(from, N);
			profit += get_temp_profit(from, max_idx);
			if (from == max_idx) {
				if (is_desc(from)) break; // remains have descendent values => break
				else from++;
			} else from = max_idx + 1;
		}
		cout << profit << '\n';
		profit = 0;
	}
}
