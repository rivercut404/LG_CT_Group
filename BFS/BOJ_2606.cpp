#include "bits/stdc++.h"
using namespace std;

int N, M;
int visited[101];
vector< vector<int> > adj_list(101);

int bfs() 
{
	queue<int> Q; int warms = 0;
	visited[1] = 1;
	Q.push(1);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (auto cptr : adj_list[cur]) {
			if (visited[cptr] == 0) {
				visited[cptr] = 1;
				Q.push(cptr); warms++;
			}
		}
	}
	return warms;
}

int main(void) 
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	while (M--) {
		int i, j;
		cin >> i >> j;
		adj_list[i].push_back(j); adj_list[j].push_back(i);
	}

    int warms = bfs();
	cout << warms;
}
