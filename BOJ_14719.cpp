#include "bits/stdc++.h"
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, W;
	int rain = 0;
	cin >> H >> W;

	vector<int> blocks(W); 
	for (int i=0; i<W; i++)
	    cin >> blocks[i];
	
	int head = 0; int tail = 1;
	while (head != W) {
		if (blocks[head] <= blocks[head+1]) {
		// if head meets higher block then move head
			head++; tail++;
		} else if (blocks[head] > blocks[tail]) {
		// if not, move tail forward
			tail++;
		} else {
		// head and tail make a lake
			int height = blocks[head] > blocks[tail] ? blocks[head] : blocks[tail];
			for (int i=head+1; i<tail; i++) 
				rain += (height-blocks[i]);
			head = tail; tail++;
		}
	}
}
