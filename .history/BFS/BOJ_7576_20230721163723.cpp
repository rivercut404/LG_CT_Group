#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

vector< vector<int> > board;
vector< vector<int> > days;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N;

void bfs(pair<int, int> sp) {
    queue< pair<int, int> > Q;
	days[sp.X][sp.Y] = 0;
	Q.push(sp);

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
		for (int dir=0; dir<4; dir++) {
    		int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=M)
			    continue;
			if (board[nx][ny]!=0 || days[nx][ny]<=days[cur.X][cur.Y])
			    continue;
			days[nx][ny] = days[cur.X][cur.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> M >> N;

	vector<int> temp(M, -1);
	for (int i=0; i<N; i++) board.push_back(temp);

	for (int i=0; i<M; i++) temp[i] = 2002;
	for (int i=0; i<N; i++) days.push_back(temp);

	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
            cin >> board[i][j];
			if (board[i][j] == -1) 
			    days[i][j] = -1;
		}
	}

	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
            if (board[i][j] == 1) {
				bfs(make_pair(i, j));
			}
		}
	}

	int answer = 0;
	for (int i=0; i<N; i++) {
    	for (int j=0; j<M; j++) {
			if (days[i][j] == 2002) {
				answer = -1;
				cout << "-1\n";
				return 0;
			}
			if (days[i][j] < 2000 && days[i][j] > answer)
			    answer = days[i][j];
		}
	}
	if (answer == 2002)
	cout << answer << '\n';	
}
