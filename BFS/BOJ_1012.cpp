#include "bits/stdc++.h"
using namespace std;
#define X first 
#define Y second 

int board[52][52];
int visited[52][52];
int T, M, N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(pair<int, int> sp) {
    queue< pair<int,int> > Q;
	visited[sp.X][sp.Y] = 1;
	Q.push(sp);
    
	while (!Q.empty()) {
	    pair<int,int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
		    int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=M || ny<0 || ny>=N)
			    continue;
			if (visited[nx][ny] || board[nx][ny]!=1)
			    continue;
			visited[nx][ny] = 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void) 
{ 
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> T;

    while (T--) {
	    int K;
		int answer = 0;
		cin >> M >> N >> K;
		for (int i=0; i<K; i++) {
		    // Set the board
		    int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		// BFS
		for (int i=0; i<M; i++) {
		    for (int j=0; j<N; j++) {
                if (visited[i][j]==0 && board[i][j]==1) {
					answer++; bfs(make_pair(i, j));
				}
			}
		}
		
		for (int i=0; i<M; i++)
		    fill(board[i], board[i]+N, 0);
        for (int i=0; i<M; i++)
		    fill(visited[i], visited[i]+N, 0);

		cout << answer << '\n';
	}
}

