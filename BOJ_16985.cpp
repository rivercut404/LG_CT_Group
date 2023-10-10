#include "bits/stdc++.h"
using namespace std;

int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};

int visited[5][5][5];

int board[5];
int rotation[5];

int maze[5][5][5];
int maze2use[5][5][5];
int scratch[5][5];

void (*do_rotation[4])(int);

struct pos {
	int X;
	int Y;
	int Z;
} typedef pos;

void bfs(void)
{
    queue<pos> Q; 
}

void create_maze(void) 
{
	for (int i = 0; i < 5; i++) {
		int num_b = board[i]; int num_r = rotation[i];
		// rotate for r the n-th board in maze 
		// write to scratch 
		do_rotation[num_r](num_b);
	    // then copy to maze2use
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				maze2use[i][r][c] = scratch[r][c];
			}
		}
	}
}

void rotate0(int n)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scratch[i][j] = maze[n][i][j];
		}
	}
}

void rotate1(int n)
{
	// rotate the n-th board of maze cw for 90-degree
	// write to scratch board
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scratch[j][4-i] = maze[n][i][j];
		}
	}
}

void rotate2(int n)
{
	// rotate the n-th board of maze for 180-degree
	// write to scratch board
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scratch[4-i][4-j] = maze[n][i][j];
		}
	}
}

void rotate3(int n)
{
	// rotate the n-th board of maze ccw for 90-degree
	// write to scratch board
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scratch[4-j][i] = maze[n][i][j];
		}
	}
}

void set_rotate_funcs(void) 
{
	do_rotation[0] = rotate0;
	do_rotation[1] = rotate1;
	do_rotation[2] = rotate2;
	do_rotation[3] = rotate3;
}

void get_rotations(int n) 
{
    if (n == 5) {
		// Base case
		for (int i = 0; i < 5; i++) cout << rotation[i] << ' ';
		cout << '\n';

		return;
	}
    // Recursion : 4H5
	for (int i = 0; i < 4; i++) {
		rotation[n] = i;
		get_rotations(n+1);
	}
}

void test_func(void) 
{
    board[0] = 2; board[1] = 3; board[2] = 0; board[3] = 4; board[4] = 1;
    rotation[0] = 0; rotation[1] = 2; rotation[2] = 1; rotation[3] = 0; rotation[4] = 3;

	create_maze();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) cout << maze2use[i][j][k] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> maze[i][j][k];
			}
		}
	}

    set_rotate_funcs();

	test_func();

	// for(int b1 = 0; b1 < 5; b1++) {
	// 	board[0] = b1;
	// 	for(int b2 = 0; b2 < 5; b2++) {
	// 		if (b2 == b1) continue; 
	// 		board[1] = b2;
	// 		for (int b3 = 0; b3 < 5; b3++) {
    //             if (b3 == b1 || b3 == b2) continue;
	// 			board[2] = b3;
	// 			for (int b4 = 0; b4 < 5; b4++) {
	// 				if (b4 == b1 || b4 == b2 || b4 == b3) continue;
	// 				board[3] = b4;
	// 				for (int b5 = 0; b5 < 5; b5++) {
	// 					if (b5 == b1 || b5 == b2 || b5 == b3 || b5 == b4) continue;
	// 					board[4] = b5;  // Complete the order of boards 

	// 					// Main routine
	
	// 				}
	// 			}
	// 		}
	// 	}
	// }
}
