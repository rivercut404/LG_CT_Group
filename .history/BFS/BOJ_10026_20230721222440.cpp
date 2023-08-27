#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
vector<string> board;
int visited[102][102];

void bfs(pair<int,int> sp) {
    queue< pair<int,int> > Q;
	visited[sp.X][sp.Y] = 1;
	Q.push(sp);

	while (!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=N)
			    continue;
			if (visited[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) 
			    continue;
			visited[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int rgb = 0;
	int gray = 0;

	cin >> N;
	for (int i=0; i<N; i++) {
    	string row;
		cin >> row;
		board.push_back(row);
	}
    
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (visited[i][j] == 0) {
				rgb++;
				bfs(make_pair(i, j));
			}
		}
	}
	for (int i=0; i<N; i++) {
        string temp = "";
    	for (int j=0; j<N; j++) {
			if (board[i][j]=='B' || board[i][j]=='R')
			    temp += board;
			else
			    temp += 'R';

			visited[i][j] = 0;
		}
		board[i] = temp;
	}
    for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (visited[i][j] == 0) {
				gray++;
				bfs(make_pair(i, j));
			}
		}
	}
	cout << rgb << ' ' << gray;
}
