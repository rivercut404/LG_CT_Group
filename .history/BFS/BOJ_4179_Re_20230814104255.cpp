#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> board;
int dist_J[1002][1002];
int dist_F[1002][1002];
pair<int,int> pos_J, pos_F;

void bfs(pair<int,int> sp, bool is_J) {
    queue< pair<int,int> > Q;

}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Get the inputs
    int R, C; cin >> R >> C;
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