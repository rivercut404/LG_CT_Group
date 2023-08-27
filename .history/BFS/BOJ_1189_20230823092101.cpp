#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int R, C, K;
vector<string> board;
int dist[5][5];
int ways;

void bfs(void) 
{
	vector< pair<int,int> > S;
	dist[0][0] = 1;
	S.push_back(make_pair(0,0));
	
	while (!S.empty()) {
		pair<int,int> cur = S.back(); S.pop_back();
		if (cur.X == R-1 && cur.Y == C-1) ways++;
		else if (dist[cur.X][cur.Y] == K) continue;
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
			if (board[nx][ny] == 'T') continue;
			if (nx==R-1 && ny==C-1) {
				if (dist[cur.X][cur.Y]!=K-1) continue;
				else {
					S.push_back(make_pair(nx,ny));
					continue;
				}
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			S.push_back(make_pair(nx,ny));
		}
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
	bfs();
	cout << ways << '\n';
}
