#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second
typedef pair<int,int> point;

int N, M;
vector< vector<int> > board;
int visited[8][8];
point empties[64];
vector<point> virus;
int n_effected = 64;
int tmp;
int n_wall; 
int n_empty;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(point sp) {
/**
 * Function for counting the blocks to be effected 
 * Beginning from virus block, traverse the adjacent empty blocks 
 * each movement to the empty block, tmp++ 
 */
    queue<point> Q; 
	visited[sp.X][sp.Y] = 1; 
	tmp++;
	Q.push(sp);

	while (!Q.empty()) {
		point cur = Q.front(); Q.pop();
        for (int dir = 0; dir<4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
			if (board[nx][ny] == 1 || visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			tmp++;
			Q.push(make_pair(nx,ny));
		}
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;
	for (int r=0; r<N; r++) {
	    vector<int> temp(M);
        for (int c=0; c<M; c++) {
            cin >> temp[c];
			if (temp[c] == 0) {
                empties[n_empty] = make_pair(r,c);
				n_empty++;
			} else if (temp[c] == 1) n_wall++;
			else {  // block is 2 : virus
                virus.push_back(make_pair(r,c));
			}
		}
        board.push_back(temp);
	}

    // Execute BFS iteratively (for every comb. of 3 empties)
	for (int i=0; i<n_empty-2; i++) {
		for (int j=i+1; j<n_empty-1; j++) {
			for (int k=j+1; k<n_empty; k++) {
				board[empties[i].X][empties[i].Y] = 1;
				board[empties[j].X][empties[j].Y] = 1;
				board[empties[k].X][empties[k].Y] = 1;
				for (auto v : virus) {
					if (tmp >= n_effected) break;
					if (visited[v.X][v.Y]) continue;
                    bfs(v);
				}
				if (tmp < n_effected) n_effected = tmp;
				board[empties[i].X][empties[i].Y] = 0;
				board[empties[j].X][empties[j].Y] = 0;
				board[empties[k].X][empties[k].Y] = 0;
				tmp = 0;
				// Set visited to zeros
				for (int r=0; r<N; r++) fill(visited[r], visited[r]+M, 0);
			}
		}
	}
    
    cout << N*M - (n_wall + n_effected + 3) << '\n';
}
