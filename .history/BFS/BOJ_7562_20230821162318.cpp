#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[] = {2, 1, -2, -1, -2, -1, 2, 1};
int visited[300][300];
pair<int,int> knight, target;

void bfs() 
{
	queue< pair<int,int> > Q; 
    visited[sp.X][sp.Y] = 1;
	Q.push(sp);

	while (!Q.empty()) {
		pair<int,int> cur = Q.front(); Q.pop();
		if 
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T; cin >> T;

	while (T--) {
		int I; cin >> I;
		cin >> knight.X >> knight.Y;
		cin >> target.X >> target.Y;

	}
}

