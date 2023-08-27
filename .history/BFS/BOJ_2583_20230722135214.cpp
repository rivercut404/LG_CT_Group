#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[102][102];
int M, N;

int bfs(pair<int,int> sp) {
    int blocks = 0;
    queue< pair<int,int> > Q;
    board[sp.X][sp.Y] = 1;
	Q.push(sp); blocks++;

	while (!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=M || ny<0 || ny>=N)
				continue;
			if (board[nx][ny])
			    continue;
			board[nx][ny] = 1;
			Q.push(make_pair(nx,ny)); blocks++;
		}
	}

	return blocks;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int rec;
	pair<int,int> low, high;

    cin >> M >> N >> rec;
	while (rec--) {
	    cin >> low.Y >> low.X >> high.Y >> high.X;
		for (int i=low.X; i<high.X; i++) {
			for (int j=low.Y; j<high.Y; j++)
			    if (board[i][j] == 0) board[i][j] = 1;
		}
	}

	vector<int> sections;
	for (int i=0; i<M; i++) {
    	for (int j=0; j<N; j++) {
    		if (board[i][j]) continue;
			int section = bfs(make_pair(i, j));
			sections.push_back(section);
		}
	}

	cout << sections.size() << '\n';
	for (auto s : sections) cout << s << ' ';
}
