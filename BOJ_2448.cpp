#include "bits/stdc++.h"
using namespace std;

int N;
char **stars;

void print_star(int x, int y, int size)
{
	if (size == 3) {
	// Base case
		stars[x][y] = '*';
		stars[x+1][y-1] = '*'; stars[x+1][y+1] = '*';
		for (int i=y-2; i<=y+2; i++) stars[x+2][i] = '*';
	} else {
	// Recursion
		size = (int)(size/2);
		print_star(x, y, size);
		print_star(x+size, y-size, size);
		print_star(x+size, y+size, size);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	stars = new char *[N];
	for (int i=0; i<N; i++) {
		stars[i] = new char[2*N-1];
		for (int j=0; j<2*N-1; j++)
			stars[i][j] = ' ';
	}
    
	print_star(0, N-1, N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<2*N-1; j++)
			cout << stars[i][j];
	    cout << '\n';
	}

	for (int i=0; i<N; i++)
		delete(stars[i]);
	delete(stars);
}
