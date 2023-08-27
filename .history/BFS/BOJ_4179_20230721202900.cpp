#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> board;
int visited[1002][1002];
int R, C;

void bfs(pair<int, int> sp) {
    queue< pair<int, int> > Q;
    visited[sp.X][sp.Y] = 0;
	Q.push(sp);

	while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=R || ny<0 || ny>=C) 
			    continue;
			if (board[nx][ny] != '.') 
			    continue;
			if (visited[nx][ny] == -1 || visited[nx][ny] > visited[cur.X][cur.Y]+1) {
			    visited[nx][ny] = visited[cur.X][cur.Y] + 1;
		    	Q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
	vector< pair<int, int> > exit;

    cin >> R >> C;

	for (int i=0; i<R; i++) {
    	string row;
		cin >> row;
		board.push_back(row);
	}

	for (int i=0; i<R; i++) {
		if (board[i][0] == '.')
		    exit.push_back(make_pair(i, 0));
		if (board[i][C-1] == '.')
		    exit.push_back(make_pair(i, C-1));
	}

	for (int i=1; i<C-1; i++) {
		if (board[0][i] == '.') exit.push_back(make_pair(0, i));
		if (board[R-1][i] == '.') exit.push_back(make_pair(R-1, i));
	}

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			visited[i][j] = -1;
		}
	}
    pair<int, int> J;
	vector< pair<int, int> > F;
	vector<int> dist_J;
	vector<int> dist_F;

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
		    if (board[i][j] == 'J')
			    J = make_pair(i, j);
			if (board[i][j] == 'F')
			    F.push_back(make_pair(i, j));
		}
	}
	bfs(J);
    for (auto p : exit) 
	    dist_J.push_back(visited[p.X][p.Y]);

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			visited[i][j] = -1;
		}
	}
	for (auto f : F)
	    bfs(f);

    for (auto p : exit) 
	    dist_F.push_back(visited[p.X][p.Y]);
    
	int min_t = 2002;
	for (int i=0; i<dist_F.size(); i++) {
    	if (dist_J[i] != -1 && dist_J[i] < dist_F[i]) {
		    if (dist_J[i] < min_t) min_t = dist_J[i];
		}
	}

	if (min_t == 2002)
	    cout << "IMPOSSIBLE";
	else
	    cout << min_t+1;
}
