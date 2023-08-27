#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[100][100];
int board[100][100];
int N, M, T;
int t_sword = 10000;

void bfs(void) {
    queue< pair<int,int> > Q;
	visited[0][0] = 1;
	Q.push(make_pair(0,0));

	while (!Q.empty()) {
		pair<int,int> cur = Q.front();
		Q.pop();
		if (board[cur.X][cur.Y] == 2) {
			int temp = visited[cur.X][cur.Y] + (N-cur.X) + (M-cur.Y) - 1;
			if (temp < t_sword) t_sword = temp;
			continue;
		}
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx<0 || nx>=N || ny<0 || ny>=M) 
			    continue;
			if (visited[nx][ny] || board[nx][ny]==1)
			    continue;

			visited[nx][ny] = visited[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void) 
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int shortest;
    cin >> N >> M >> T;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) 
			cin >> board[i][j];
	}
    bfs();

	if (visited[N-1][M-1] == 0) shortest = 10000;
	else shortest = visited[N-1][M-1] - 1;
	if (shortest > t_sword) shortest = t_sword;
	
    if (shortest <= T) cout << shortest;
	else cout << "Fail";
}
