#include "bits/stdc++.h"
using namespace std;
#define open 0
#define close 1
typedef pair<int,int> date_t; 

bool compare_date(date_t A, date_t B) {
	if (A.first != B.first) return A.first < B.first;
	else return A.second < B.second;
}

bool compare_open(array<date_t, 2> A, array<date_t, 2> B) {
	return compare_date(A[open], B[open]);
}

bool compare_close(array<date_t, 2> A, array<date_t, 2> B) {
	return compare_date(A[close], B[close]);
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
	vector< array<date_t, 2> > flowers(N);
	// Get opening and closing date for each flower
	for (int i=0; i<N; i++) {
		cin >> flowers[i][open].first >> flowers[i][open].second;
		cin >> flowers[i][close].first >> flowers[i][close].second;
	}
	// Sort by the opening date
	sort(flowers.begin(), flowers.end(), compare_open);
	// Pick a first flower 
	date_t start = make_pair(3, 1); date_t end = make_pair(11, 30);
	int i = 0; int in_garden = 0; int picked = 0;
	while (compare_date(flowers[i][open], start)) {
		if (compare_close(flowers[picked], flowers[i])) picked = i;
		i++;
		if (i >= N) {
			in_garden = -1; 
			break;
		}
	} // flowers[picked] is the best for a first one
	if (in_garden == -1 || compare_date(start, flowers[0][open])) {
		cout << 0; return 0;
	} else in_garden++;
	// Pick the best flowers in greedy view
	while (compare_date(flowers[picked][close], end)) {
		int tmp = i; // temporal best flower
		while (compare_date(flowers[i][open], flowers[picked][close])) {
		// Must pick a flower opening before picked closed
			if (compare_close(flowers[tmp], flowers[i])) tmp = i; // update temporal best
			i++;
			if (i >= N && compare_date(flowers[tmp][close], end)) {
				cout << 0; return 0;
			}
		}
	}
	
}
