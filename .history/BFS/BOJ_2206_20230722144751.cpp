#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<string> board;
int dist[1002][1002];

void bfs(pair<int,int> sp) {
    queue< pair<int,int> > Q;
	dist[sp.X][sp.Y] = 0;
	Q.push(sp);

	while (!Q.empty()) {
	    pair<int,int> cur = Q.front(); Q.pop();
        for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=M)
			    continue;
			if (dist[nx][ny]>=0 || board[nx][ny]!=0)
			    continue
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void) 
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin  >> N >> M;
    for (int i=0; i<N; i++) {
    	string row;
		cin >> row;
		board.push_back(row);
		fill(dist[i], dist[i]+M, -1);
	}
    bfs(make_pair(0,0));
	int min_dist = dist[N-1][M-1];
	vector< pair<int,int> > walls;
	// vector<int> dist_to_wall;

	// Get the list of reachable wall blocks from O
	for (int i=0; i<N; i++) {
    	for (int j=0; j<M; j++) {
		    if (board[i][j]==1) {
    			for (int dir=0; dir<4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx<0 || nx>=N || ny<0 || ny>=M)
						continue;
					if (board[nx][ny]==0 && dist[nx][ny]>=0) {
					    walls.push_back(make_pair(i,j));
					}
				}    	
			}
		}
	}
	for (auto wall : walls) {
	    int to_wall = 2002;
	    // Calculate the distance of each wall block
    	for (int dir=0; dir<4; dir++) {
			int nx = wall.X + dx[dir];
			int ny = wall.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=M)
				continue;
			if (board[nx][ny]!=0 || dist[nx][ny]<0)
			    continue;
			if (to_wall > dist[nx][ny]) to_wall = dist[nx][ny];
		// Calculate distance from wall to the goal
		for (int i=0; i<N; i++) fill(dist[i], dist[i]+M, -1);
		bfs(wall);
		if (dist[N-1][M-1] < 0) continue;
		if (min_dist > to_wall+dist[N-1][M-1]) min_dist = to_wall + dist[N-1][M-1];
	}

	cout << min_dist;
}
