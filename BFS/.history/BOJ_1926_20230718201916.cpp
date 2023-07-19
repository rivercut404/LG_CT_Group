#include "bits/stdc++.h"
using namespace std;
#define X first;
#define Y second;

int n, m;
vector< vector<int> > board(n);
int visited[501][501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(pair<int, int> sp) {
    int area = 0;
    queue< pair<int, int> > Q;
    Q.push(sp); // 큐에 시작점인 (0, 0)을 삽입.

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        area++;
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue; // 범위 밖일 경우 넘어감
            if(visited[nx][ny] || board[nx][ny] != 1) 
                continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push(make_pair(nx, ny));
        }
    }
    return area;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int max_area = 0;
    int num = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }        

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==1 && visited[i][j]!=0) {
                num++;
                pair<int, int> sp = make_pair(i, j);
                int temp = bfs(sp);
                if (temp > max_area)
                    max_area = temp;
            }
        }
    }
    cout << num << '\n' << max_area;
}