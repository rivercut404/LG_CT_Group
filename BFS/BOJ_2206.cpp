#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second
#define NOT_REACHABLE 1000001
typedef pair<int,int> point;

int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char board[1001][1001];
int from_s[1001][1001];
int from_d[1001][1001];

int sp;  // Distance of the shortest path

void bfs(point p, int (*visited)[1001]) 
{
    queue<point> Q;
	visited[p.X][p.Y] = 1;
	Q.push(p);

	while (!Q.empty()) {
		point cur = Q.front(); Q.pop();
		// if (visited[cur.X][cur.Y] == sp) return;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == '1' || visited[nx][ny] != 0) continue;
			visited[nx][ny] = visited[cur.X][cur.Y] + 1;
		    // if (nx == N-1 &&  ny == M-1) return;
			Q.push(make_pair(nx,ny));
		}
	}
}

bool to_break(int r, int c)
{
	int n;
	for (int dir = 0; dir < 4; dir++) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		else if (board[nx][ny] == '0') n++;
	}
	if (n >= 2) return true;
	else return false;
}

int main(void) 
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
    for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
    // Execute bfs and get the dist from S, D
    bfs(make_pair(0,0), from_s);
    bfs(make_pair(N-1,M-1), from_d);
	sp = from_s[N-1][M-1] != 0 ? from_s[N-1][M-1] : NOT_REACHABLE;

    for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
    		if (board[r][c] == '0') continue;
			else if (to_break(r, c)) {
				for (int i = 0; i < 3; i++) {
					for (int j = i+1; j < 4; j++) {
						point p1 = make_pair(r + dx[i], c + dy[i]);
						point p2 = make_pair(r + dx[j], c + dy[j]);
						if (p1.X < 0 || p1.X >= N || p1.Y < 0 || p1.Y >= M) continue;
						if (p2.X < 0 || p2.X >= N || p2.Y < 0 || p2.Y >= M) continue;
						if (board[p1.X][p1.Y] == '1' || board[p2.X][p2.Y] == '1') continue;
						if (from_s[p1.X][p1.Y] != 0 && from_d[p2.X][p2.Y] != 0) {
						    // Found the block to break!
							int tmp = from_s[p1.X][p1.Y] + from_d[p2.X][p2.Y] + 1;
							if (sp > tmp) sp = tmp;
						}
						if (from_s[p2.X][p2.Y] != 0 && from_d[p1.X][p1.Y] != 0) {
						    // Found the block to break!
							int tmp = from_d[p1.X][p1.Y] + from_s[p2.X][p2.Y] + 1;
							if (sp > tmp) sp = tmp;
						}
					}
				}
			}
		}
	}
    if (sp == NOT_REACHABLE) {
		cout << -1 << '\n';
		return 0;
	}
	cout << sp << '\n';
}
