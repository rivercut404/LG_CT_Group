#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> board;
int dist_J[1002][1002];
int dist_F[1002][1002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C; cin >> R >> C;
    for (int i=0; i<R; i++) {
        string row; cin >> row;
        board.push_back(row);
    }
}