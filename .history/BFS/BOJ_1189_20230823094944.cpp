#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int R, C, K;
vector<string> board;
int dist[5][5];
int visited[5][5];
int ways;

void bfs(int dist, pair<int,int> cur) 
{
	if (dist == K) {
		if (cur.X == R-1 && cur.Y == C-1) ways++;
		return;
	} 

	for (int dir=0; dir<4; dir++) {
		int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
		if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
		if (board[nx][ny] == 'T') continue;

		bfs(dist+1, make_pair(nx,ny));
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> K;
	for (int i=0; i<R; i++) {
		string tmp; cin >> tmp;
		board.push_back(tmp);
	}
	bfs(1, make_pair(0,0));
	cout << ways << '\n';
}
