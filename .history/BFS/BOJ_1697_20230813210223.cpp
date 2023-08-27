#include "bits/stdc++.h"
using namespace std;
#define lim 100000

int N, K;
int dist[100002];

void bfs(void) {
    queue<int> Q;
	dist[N]++;
	Q.push(N);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (cur == K) break;

		if (cur-1 >= 0) {
			if (dist[cur-1] == 0) {
				dist[cur-1] = dist[cur] + 1;
				Q.push(cur-1);
			}
		}
		if (cur+1 <= lim) {
			if (dist[cur+1] == 0) {
				dist[cur+1] = dist[cur] + 1;
				Q.push(cur+1);
			}
		}
		if (2*cur <= lim) {
			if (dist[2*cur] == 0) {
				dist[2*cur] = dist[cur] + 1;
				Q.push(2*cur);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int answer;
	cin >> N >> K;

	if (N > K) answer = N-K;
	else {
		bfs();
		answer = dist[K] - 1;
	}

	cout << answer;
}
