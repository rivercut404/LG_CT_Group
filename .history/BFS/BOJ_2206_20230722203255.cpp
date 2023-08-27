#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<string> board;

void bfs(pair<int,int> sp, int dist[][1002]) {
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
			if (dist[nx][ny]>=0 || board[nx][ny]!='0')
			    continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void) 
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int dist[1002][1002];
	int dist_goal[1002][1002];

	cin  >> N >> M;
    for (int i=0; i<N; i++) {
    	string row;
		cin >> row;
		board.push_back(row);
		fill(dist[i], dist[i]+M, -1);
		fill(dist_goal[i], dist_goal[i]+M, -1);
	}
    bfs(make_pair(0,0), dist);
	bfs(make_pair(N-1,M-1), dist_goal);
	int min_dist = 2002;
	if (dist[N-1][M-1] >= 0) min_dist = dist[N-1][M-1];
	vector< pair<int,int> > walls;

	// Get the list of reachable wall blocks from O
	for (int i=0; i<N; i++) {
    	for (int j=0; j<M; j++) {
		    if (board[i][j]=='1') {
    			for (int dir_w=0; dir_w<4; dir_w++) {
					for (int dir_g=0; dir_g<4; dir_g++) {
						if (dir_w == dir_g) continue;

						int nx = i + dx[dir_w]; int ny = j + dy[dir_w];
						int gx = i + dx[dir_g]; int gy = j + dy[dir_g];
						if (nx<0 || nx>=N || ny<0 || ny>=M)
							continue;
						if (gx<0 || gx>=N || gy<0 || gy>=M)
							continue;
						if (board[nx][ny]=='0' && dist[nx][ny]>=0 &&
						    board[gx][gy]=='0' && dist_goal[gx][gy]>=0) {
							walls.push_back(make_pair(i,j));
							if (dist[i][j]>=0 && dist[i][j]>dist[nx][ny]+1) dist[i][j] = dist[nx][ny] + 1;
							if (dist_goal[i][j]>=0 && dist_goal[i][j]>dist[gx][gy]+1) dist_goal[i][j] = dist_goal[gx][gy] + 1;
						}
					}
				}    	
			}
		}
	}

	for (auto wall : walls) {
		int x = wall.X; int y = wall.Y;
		if (min_dist > dist[x][y] + dist_goal[x][y])
		    min_dist = dist[x][y] + dist_goal[x][y];
	}

	// for (auto wall : walls) {
	//     int to_wall = 2002;
	//     // Calculate the distance of each wall block
    // 	for (int dir=0; dir<4; dir++) {
	// 		int nx = wall.X + dx[dir];
	// 		int ny = wall.Y + dy[dir];
	// 		if (nx<0 || nx>=N || ny<0 || ny>=M)
	// 			continue;
	// 		if (board[nx][ny]!='0' || dist[nx][ny]<0)
	// 		    continue;
	// 		if (to_wall > dist[nx][ny]+1) to_wall = dist[nx][ny]+1;
	// 	}
	// 	// Calculate distance from wall to the goal
	// 	for (int i=0; i<N; i++) fill(dist[i], dist[i]+M, -1);
	// 	bfs(wall);
	// 	if (dist[N-1][M-1] < 0) continue;
	// 	if (min_dist > to_wall+dist[N-1][M-1]) min_dist = to_wall + dist[N-1][M-1];
	// }

	if (min_dist == 2002) cout << -1;
	else cout << min_dist+1;
}
