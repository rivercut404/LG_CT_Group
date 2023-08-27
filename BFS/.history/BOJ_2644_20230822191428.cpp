#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int n, m, A, B;
int adj_mat[101][101];
int visited[101];

void bfs(int from)
{
	queue<int> Q;
	visited[from] = 1;
	Q.push(from);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == B) break;
		for (int i=1; i<=n; i++) {
			if (adj_mat[cur][i] == 0 || visited[i] != 0) continue;
			visited[i] = visited[cur] + 1;
			Q.push(i);
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> A >> B;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj_mat[x][y] = 1; adj_mat[y][x] = 1;
	}
	bfs(A);
	cout << visited[B]-1 << '\n';
}
