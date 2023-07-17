#include "bits/stdc++.h"
using namespace std;

vector< deque<int> > gear_set(6);

void cw_rotate(int n) {
    if (n>4 || n<1)
        return;  

    int temp = gear_set[n].back();
    gear_set[n].pop_back();
    gear_set[n].push_front(temp);
}
void ccw_rotate(int n) {
    if (n>4 || n<1)
        return;  

    int temp = gear_set[n].front();
    gear_set[n].pop_front();
    gear_set[n].push_back(temp);
}

void rotate_gear(int n, int rot_type) {
    switch (rot_type)
    {
    case 1:
        // CW rotate
        cw_rotate(n);
        if (gear_set[n][6] != gear_set[n-1][2])
            ccw_rotate(n-1);
        if (gear_set[n][2] != gear_set[n+1][6])
            ccw_rotate(n+1);
        break;
    
    case -1:
        // CCW rotate
        ccw_rotate(n);
        if (gear_set[n][6] != gear_set[n-1][2])
            cw_rotate(n-1);
        if (gear_set[n][2] != gear_set[n+1][6])
            cw_rotate(n+1);
        break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<4; i++) {
        string gear;
        cin >> gear;
        for (int j=0; j<8; j++) {
            gear_set[i].push_back(gear[j]);
        }
    }
    // Rotate N times
    int N, gear_num, rot_type;
    cin >> N;
    while (N--) {
        cin >> gear_num >> rot_type;
        rotate_gear(gear_num, rot_type);
    }

    int score = gear_set[1][0] + 2*gear_set[2][0] + 4*gear_set[3][0] + 8*gear_set[4][0];
    cout << score;
}