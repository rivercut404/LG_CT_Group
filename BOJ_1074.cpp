#include "bits/stdc++.h"
using namespace std;

int N;
int r, c;
int order;

void trav_z(int x, int y, int size) 
{
	// Base case
	if (size == 2) {
		if (x == r && y == c) return;
		else if (x == r && y != c) {
			order += 1;
			return;
		} else if (x != r && y == c) {
			order += 2;
			return;
		} else {
			order += 3;
			return;
		}
	} else {
	// divide into 4 sections
	    size = (int)(size / 2);
		int blocks = size*size;
		if (x<=r && x+size>r && y<=c && y+size>c) {
			trav_z(x, y, size);
		} else if (x<=r && x+size>r && y+size<=c && y+2*size>c) {
			order += blocks;
			trav_z(x, y+size, size);
		} else if (x+size<=r && x+2*size>r && y<=c && y+size>c) {
			order += 2*blocks;
			trav_z(x+size, y, size);
		} else {
			order += 3*blocks;
			trav_z(x+size, y+size, size);
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> r >> c;
	int size = 1;
	while (N--) size = 2 * size;
	trav_z(0, 0, size);
	cout << order << '\n';
}
