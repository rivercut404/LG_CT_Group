#include "bits/stdc++.h"
using namespace std;
#define open 0
#define close 1
typedef pair<int,int> date_t; 

bool compare(vector<date_t[2]> A, vector<date_t[2]> B) {
	
}

int date_to_dec(date_t date) {
	if (date.first <= 2) return 1;
	else if (date.first == 12) return 275;
	else if (date.first == 3) return date.second;
	else if (date.first == 4) return 31+date.second;
	else if (date.first == 5) return 61+date.second;
	else if (date.first == 6) return 92+date.second;
	else if (date.first == 7) return 122+date.second;
	else if (date.first == 8) return 153+date.second;
	else if (date.first == 9) return 184+date.second;
	else if (date.first == 10) return 214+date.second;
	else if (date.first == 11) return 245+date.second;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	vector<date_t[2]> flowers(N);
	// Get open and closing date for each flower
	for (int i=0; i<N; i++) {
		cin >> flowers[i][open].first >> flowers[i][open].second;
		cin >> flowers[i][close].first >> flowers[i][close].second;
	}
}
