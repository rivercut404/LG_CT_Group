#include "bits/stdc++.h"
using namespace std;

int N;
int num[2];
int paper[128][128];

void check_color(int x, int y, int size) {
/* 
 * x: beginning index of X-axis
 * y: beginning index of Y-axis
 * size: the size of the paper 
 */
	int ref = paper[x][y];
	bool unicolored = true;
	for (int i=x; i<x+size; i++) {
		for (int j=y; j<y+size; j++) {
			if (paper[i][j] != ref) unicolored = false;
		}
	}
	// Base case
	if (unicolored) {
		num[ref]++;
		return;
	} else {
	// Recursion
		check_color(x, y, (int)size/2);
		check_color(x + (int)size/2, y, (int)size/2);
		check_color(x, y + (int)size/2, (int)size/2);
		check_color(x + (int)size/2, y + (int)size/2, (int)size/2);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			cin >> paper[i][j];
	}

	check_color(0, 0, N);
	cout << num[0] << '\n' << num[1] << '\n';
}
