#include "bits/stdc++.h"
using namespace std;

int F, S, G, U, D;
int visited[1000003];

int bfs(int S) {
    queue<int> Q;
	visited[S]++; Q.push(S);

	while(!Q.empty()) {
	    int cur = Q.front(); Q.pop();
		if (cur == G) return visited[cur]-1;
		
		if (cur+U <= F && visited[cur+U] == 0) {
			visited[cur+U] = visited[cur] + 1;
			Q.push(cur+U);
		}
		if (cur-D > 0 && visited[cur-D] == 0) {
			visited[cur-D] = visited[cur] + 1;
			Q.push(cur-D);
		}
	}
	return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	int click = bfs(S);
	if (click != -1) cout << click;
	else cout << "use the stairs";
}
