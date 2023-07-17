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
        for (int j=0; j<W; j++) {
            char state;
            cin >> state;

            if (state == 'c') {
                rain_t[i][j] = 0;
            }
        }
    }

    for (int i=0; i<H; i++) {
        for (int j=W-1; j>0; j--) {
            if (rain_t[i][j] < 0) {
                // Check the prev sec. has cloud
                for (int k=j; k>=0; k--) {
                    if (rain_t[i][k] == 0) {
                        // Found the closest cloud
                        for (int l=k; l<=j; l++) {
                            rain_t[i][l] = l-k;
                        }
                        break;
                    }
                }
            }
        }
    }
}