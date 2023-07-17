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

    int x = X - layer[i-1];

    if (layer_x%2 == 0) 
        cout << x << '/' << layer_x + 1 - x;
    else 
        cout << layer_x + 1 -x << '/' << x;
}