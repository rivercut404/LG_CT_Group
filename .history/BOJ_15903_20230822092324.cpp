#include "bits/stdc++.h"
using namespace std;

int n, m;
char numbers[500000000];

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int max_n = 0;
	for (int i=0; i<n; i++) {
		int num; cin >> num;
		numbers[num]++;
		if (num > max_n) max_n = num;
	}
	int num;
	int cards[2] = {0, 0};
	while (m--) {
		int cnt = 0; num = cards[0] != 0 ? cards[0] : cards[1];
		while (cnt != 2) {
			if (numbers[num] != 0) {
				cards[cnt] = num;
				numbers[num]--;
				cnt++; 
				continue;
			}
			num++;
		}
		int sum = cards[0] + cards[1];
		numbers[sum] += 2;
		if (sum > max_n) max_n = sum;
	}
	int score = 0;
	for (int i=cards[0]; i<max_n+1; i++) {
		if (numbers[i]) score += i*numbers[i];
	}
	cout << score << '\n';
}
