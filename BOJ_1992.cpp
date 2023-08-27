#include "bits/stdc++.h"
using namespace std;

int N;
string image[64];
vector<char> compressed;

void quad_tree(int x, int y, int size) 
{
	char ref = image[x][y];
	bool unicolored = true;
	for (int i=x; i<x+size; i++) {
		for (int j=y; j<y+size; j++) {
			if (image[i][j] != ref) unicolored = false;
		}
	}
	
	if (unicolored) {
	// Base case
		compressed.push_back(ref);
	}

	else {
	// Go recursion 
		compressed.push_back('(');
		quad_tree(x, y, (int)size/2);
		quad_tree(x, y + (int)size/2, (int)size/2);
		quad_tree(x + (int)size/2, y, (int)size/2);
		quad_tree(x + (int)size/2, y + (int)size/2, (int)size/2);
		compressed.push_back(')');
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0; i<N; i++) 
		cin >> image[i];

	quad_tree(0, 0, N);

	for (auto c : compressed) 
		cout << c;
}
