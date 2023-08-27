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

	for (int i=0; i<N; i++) 
		cout << flowers[i][open].first << ' ' << flowers[i][open].second << '~' << flowers[i][close].first << ' ' << flowers[i][close].second << '\n';
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
	// cout << flowers[picked][open].first << ' ' << flowers[picked][open].second << '~' << flowers[picked][close].first << ' ' << flowers[picked][close].second << '\n';
	// Pick the best flowers in greedy view
	while (compare_date(flowers[picked][close], end)) {
		int tmp = i; // temporal best flower
		while (compare_date(flowers[i][open], flowers[picked][close])) {
		// Must pick a flower opening before picked closed
			if (compare_close(flowers[tmp], flowers[i])) tmp = i; // update temporal best
			i++;
			if (i >= N) {
				if (compare_date(flowers[tmp][close], end)) {
					cout << 0; return 0;
				} else { // Have picked the last flower
					cout << in_garden + 1; return 0;
				} 
			}
		}
		in_garden++; picked = tmp;
		// cout << flowers[picked][open].first << ' ' << flowers[picked][open].second << '~' << flowers[picked][close].first << ' ' << flowers[picked][close].second << '\n';
	}
	cout << in_garden;	
}
