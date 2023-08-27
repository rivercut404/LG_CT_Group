#include "bits/stdc++"
using namespace std;
#define X first
#define Y second

int N, M;
int board[302][302];
int visited[302][302];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int how_melt(pair<int,int> p) {
    int num = 0;
	for (int dir=0; dir<4; dir++) {
        int nx = p.X + dx[dir];
		int ny = p.Y + dy[dir];
		if (nx<0 || nx>=N || ny<0 || ny>=M)
		    continue;
		if (board[nx][ny] == 0)
		    num++;
	}
	return num;
}

void melt_ice() {
    for (int i=0; i<N; i++) {
    	for (int j=0; j<N; j++) {
		    int melts = how_melt(make_pair(i, j));
			if (board[i][j] >0) 
			    board[i][j] = (board[i][j] > melts) ? board[i][j]-melts : 0;
		}
	}
}

void bfs(pair<int,int> sp) {
    queue< pair<int,int> > Q;
	visited[sp.X][sp.Y] = 1;
	Q.push(sp);

	while (!Q.empty()) {
    	pair<int,int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
    		int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=M)
				continue;
			if (visited[nx][ny] || board[nx][ny]==0)
				continue;
			visited[nx][ny] = 1;
			Q.push(make_pair(nx,ny));
		}
	}
}

int count(void) {
    int num = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j] > 0)
			    num++;
		}
	}
	return num;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
    	for (int j=0; j<M; j++) 
		    cin >> board[i][j];
	}
}
