#include "bits/stdc++.h"
using namespace std;

vector< deque<int> > gear_set(6);

void rotate_gear(int gear_num, int rot_type) {}

void cw_rotate(int n) {
    int temp = gear_set[n].back();
    gear_set[n].pop_back();
    gear_set[n].push_front(temp);
}
void ccw_rotate(int n) {}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}