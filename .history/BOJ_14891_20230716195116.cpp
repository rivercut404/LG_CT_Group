#include "bits/stdc++.h"
using namespace std;

vector< deque<int> > gear_set(6);

void rotate_gear(int n, int rot_type) {
    switch (rot_type)
    {
    case 1:
        // CW rotate
        cw_rotate(n);
        if (gear_set)
        break;
    
    case -1:
        // CCW rotate
        break;
    }
}

void cw_rotate(int n) {
    int temp = gear_set[n].back();
    gear_set[n].pop_back();
    gear_set[n].push_front(temp);
}
void ccw_rotate(int n) {
    int temp = gear_set[n].front();
    gear_set[n].pop_front();
    gear_set[n].push_back(temp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}