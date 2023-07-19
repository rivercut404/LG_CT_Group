#include <bits/stdc++.h>
using namespace std;
#define X first;
#define Y second;

int visited[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< vector<int> > board(n);
    

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }        

    
}