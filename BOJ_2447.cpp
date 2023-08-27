#include "bits/stdc++.h"
using namespace std;

int N;
char **stars;

void print_stars(int x, int y, int lv)
{
    // Base case
	if (lv == 1) 
		stars[x][y] = '*';
	else {
	// Recursion
	    lv = (int)(lv / 3);
		print_stars(x, y, lv); print_stars(x, y+lv, lv); print_stars(x, y+2*lv, lv);
		print_stars(x+lv, y, lv); print_stars(x+lv, y+2*lv, lv);
		print_stars(x+2*lv, y, lv); print_stars(x+2*lv, y+lv, lv); print_stars(x+2*lv, y+2*lv, lv);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N; 
	stars = new char *[N];
	for (int i=0; i<N; i++) {
		stars[i] = new char[N];
		for (int j=0; j<N; j++) 
			stars[i][j] = ' ';
	}
	
	print_stars(0, 0, N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
		    cout << stars[i][j];
		cout << '\n';
	}

	// Deallocate memory
    for (int i=0; i<N; i++) {
        delete[] stars[i];
    }
    delete[] stars;
}
