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
    visited[knight.X][knight.Y] = 1;
	Q.push(knight);

	while (!Q.empty()) {
		pair<int,int> cur = Q.front(); Q.pop();
		if (cur.X == target.X && cur.Y == target.Y) break;
		for (int dir=0; dir<8; dir++) {
			int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=I)
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> T;

	while (T--) {
		cin >> I;
		cin >> knight.X >> knight.Y;
		cin >> target.X >> target.Y;

	}
}

