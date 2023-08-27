#include "bits/stdc++.h"
#include <utility>
using namespace std;
#define X first
#define Y second 

/***
 Implementation Procedure

- find min and max height in map
- function that search # of regions by using BFS for some rain height
- iterate the function for rain height min to max

***/

int N;
int board[101][101];
int visited[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int rain_h;

void bfs(pair<int,int> sp) 
{
    queue< pair<int,int> > Q;
	visited[sp.X][sp.Y] = 1;
	Q.push(sp);
	
	while (!Q.empty()) {
		pair<int,int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=N) continue;
     		if (visited[nx][ny] || board[nx][ny] <= rain_h) continue;
			visited[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) 
			cin >> board[i][j];
	}

	int min_h = 101; int max_h = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j] > max_h) max_h = board[i][j];
			if (board[i][j] < min_h) min_h = board[i][j];
		}
	}
	int answer = 0;
	for (rain_h=min_h; rain_h<max_h; rain_h++) {
		int tmp = 0;
        for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (visited[i][j]==0 && board[i][j]>rain_h) {
					tmp++; 
					bfs(make_pair(i, j));
				}
			}
		}
		if (tmp > answer) answer = tmp; 
		for (int i=0; i<N; i++) fill(visited[i], visited[i]+N, 0);
	}
	cout << answer << '\n';
}
