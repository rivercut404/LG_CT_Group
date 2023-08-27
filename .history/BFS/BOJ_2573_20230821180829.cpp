#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int board[301][301];
int visited[301][301];

void melts_each_year(int i, int j) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = i + dx[dir]; int ny = j + dy[dir];
		if (board[nx][ny] == 0) cnt++;
	}
	board[i][j] = board[i][j] > cnt ? board[i][j]-cnt : 0;
}

void bfs(int i, int j) {
	queue< pair<int,int> > Q;
	visited[i][j] = 1;
	Q.push(make_pair(i,j));

	while (!Q.empty()) {
		pair<int,int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny >=M) continue;
			if (visited[nx][ny] != 0 || board[nx][ny] == 0) continue;
			visited[nx][ny] = 1; Q.push(make_pair(nx, ny));
		}
	}
}

int counts(void) {
	int cnt = 0;
	for (int i=1; i<N-1; i++) {
		for (int j=1; j<M-1; j++) {
			if (board[i][j] != 0 && visited[i][j] == 0) {
				bfs(i, j); cnt++;
			}
		}
	}
	return cnt;
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++)
			cin >> board[i][j];
	}

	int divided = 0; 
	
	while (1) {
		// Melts the ice on the map 
		for (int i=1; i<N-1; i++) {
			for (int j=1; j<M-1; j++) {
				if (board[i][j] != 0) {
					melts_each_year(i, j);
					divided++;
				}
			}
		}
		int parts = counts();
		if (parts > 1) break;
		else if (parts == 0) {
			divided = 0;
			break;
		}
		for (int i=1; i<N-1; i++)
			fill(visited[i], visited[i]+M, 0);
	}
	cout << divided;
}
