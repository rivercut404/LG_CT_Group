#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int R, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> board;
int dist[1002][1002];
pair<int,int> pos_J, pos_F;

void bfs(pair<int,int> sp) {
    queue< pair<int,int> > Q;
    dist[sp.X][sp.Y] = 1;
    Q.push(sp);

    while (!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx>=R || ny<0 || ny>=C)
                continue;
            if (board[nx][ny] != '.') continue;
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Get the inputs
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        string row; cin >> row;
        board.push_back(row);
    }
    // Find the position of J and Fire 
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == 'J') pos_J = make_pair(i,j);
            else if (board[i][j] == 'F') pos_F = make_pair(i,j);
        }
    }
}