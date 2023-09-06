#include "bits/stdc++.h"
#include <cstdlib>
using namespace std;
#define X first
#define Y second

typedef pair<int,int> point;
int t, n;
point home, fest;
vector<point> stores;
int adj[102][102];
int visited[102];
string answer = "sad";


inline int get_dist(point a, point b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void set_adjacents(point p, int idx) {
    for (int i=0; i<n; i++) {
		if (idx == i+1) continue;
		if (get_dist(p, stores[i]) <= 1000) {
			adj[idx][i+1] = 1;
			adj[i+1][idx] = 1;
		}
	}
	if (get_dist(p, home) <= 1000 && idx != 0) {
		adj[0][idx] = 1;
		adj[idx][0] = 1;
	}
	if (get_dist(p, fest) <= 1000 && idx != n+1) {
		adj[idx][n+1] = 1;
		adj[n+1][idx] = 1;
	}
}

void bfs(void) 
{
	queue<int> Q;
	visited[0] = 1;
	Q.push(0);

	while (!Q.empty()) {
	    int cur = Q.front(); Q.pop();
		if (cur == n+1) {
			answer = "happy";
			return;
		}
		for (int i=1; i<n+2; i++) {
			if (adj[cur][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				Q.push(i);
			}
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
	    // loop for each test case
		cin >> n; 
		cin >> home.X >> home.Y;
		home.X = home.X+32768; home.Y = home.Y+32768;
		for (int i=0; i<n; i++) {
			point temp; 
			cin >> temp.X >> temp.Y;
		    temp.X = temp.X+32768; temp.Y = temp.Y+32768;
			stores.push_back(temp);
		}
		cin >> fest.X >> fest.Y;
		fest.X = fest.X+32768; fest.Y = fest.Y+32768;

		// Build the adjacent matrix
		set_adjacents(home, 0);
		set_adjacents(fest, n+1);
        for (int i=0; i<n; i++) set_adjacents(stores[i], i+1);

		bfs();
		cout << answer << '\n';
		answer = "sad";
		fill(visited, visited+102, 0);
		for (int i=0; i<n+2; i++) fill(adj[i], adj[i]+102, 0);
		stores.clear();
	}
}
