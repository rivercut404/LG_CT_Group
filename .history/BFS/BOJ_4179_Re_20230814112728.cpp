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
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx,ny));
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

    int dist_J[1002][1002];
    // Calculate the distances to exits from J
    bfs(pos_J);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) dist_J[i][j] = dist[i][j];
    }
    // Set dist to zeros then get the distances from fire
    for (int i=0; i<R; i++) fill(dist[i], dist[i]+C, 0);
    bfs(pos_F);

    // Compare the distances from J and fire
    int exit_T = 1000003;
    for (int i=0; i<R; i++) {
        if (board[i][0] == '#') {} 
        else if (board[i][0]=='.' && dist_J[i][0]!=0) {
            if (dist_J[i][0] < dist[i][0] && dist_J[i][0] < exit_T) exit_T = dist_J[i][0];
        }
        if (board[i][C-1] == '#') continue;
        else if (board[i][C-1]=='.' && dist_J[i][C-1]!=0) {
            if (dist_J[i][C-1]<dist[i][C-1] && dist_J[i][C-1]<exit_T) exit_T = dist_J[i][C-1];
        }
    }
    for (int i=0; i<C; i++) {
        if (board[0][i] == '#') {}
        else if (board[0][i]=='.' && dist_J[0][i]!=0) {
            if (dist_J[0][i]<dist[0][i] && dist_J[0][i]<exit_T) exit_T = dist_J[0][i];
        }
        if (board[R-1][i] == '#') continue;
        else if (board[R-1][i]=='.' && dist_J[R-1][i]!=0) {
            if (dist_J[R-1][i]<dist[R-1][i] && dist_J[R-1][i]<exit_T) exit_T = dist_J[R-1][i];
        }
    }
    if (exit_T == 1000003) cout << "IMPOSSIBLE";
    else cout << exit_T;
}