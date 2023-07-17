#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int layer[5000];

    for (int i=0; i<5000; i++) {
        layer[i] = (int)((i*(i+1))/2);
    }

    int X, i;
    int layer_x = 0;
    cin >> X;

    for (i=1; i<4999; i++) {
        if (layer[i] >= X) {
            layer_x = i;
            break;
        }
    }

    int dist = layer[i]+1 - X;
    cout << layer_x-dist << '/' << dist+1;
}