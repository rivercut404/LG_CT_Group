#include <bits/stdc++.h>
using namespace std;
#define X first;
#define Y second;

int board[501][501] = 
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}}; // 1이 파란 칸, 0이 빨간 칸에 대응
bool visited[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue< <pair<int, int> > Q;
    
}