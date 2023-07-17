#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    int rain_t[101][101];

    cin >> H;
    cin >> W;

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) 
            rain_t[i][j] = -1;
    }

    for (int i=0; i<H; i++) {
        bool is_cloud = false;
        for (int j=0; j<W; j++) {
            char state;
            cin >> state;

            if (state == 'c') {
                rain_t[i][j] = 0;
            }
        }
    }


}