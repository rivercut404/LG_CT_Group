#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

string board[27];
int visited[27][27];
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(pair<int, int> sp) {
    int number = 0;
    queue< pair<int, int> > Q;
	visited[sp.X][sp.Y] = 1;
	Q.push(sp); number++;

	while (!Q.empty()) {
	    pair<int , int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
		    int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=N)
			    continue;
			if (visited[nx][ny] || board[nx][ny]=='0')
			    continue;
			visited[nx][ny] = 1;
			Q.push(make_pair(nx, ny)); number++;
		}
	}
	return number;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    vector<int> apts;
	cin >> N;
	for (int i=0; i<N; i++) {
	    cin >> board[i];
	}
	for (int i=0; i<N; i++) {
	    for (int j=0; j<N; j++) {
		    if (board[i][j]=='1' && visited[i][j]==0) {
			    apts.push_back(bfs(make_pair(i, j)));
			}
		}
	}
	sort(apts.begin(), apts.end());
	cout << apts.size() << '\n';
	for (auto num : apts) 
	    cout << num << '\n';
}

