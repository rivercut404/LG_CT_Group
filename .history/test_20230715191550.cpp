#include "bits/stdc++.h"
using namespace std;

int test[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    test[3] = 1;
    test[5] = 1;
    test[7] = 1;

    string center = "" ;

    for (char i=0; i<26; i++) {
        if (test[i] > 0) {
                center = center + (char)('A' + i);
        }
    }

    cout << center;
}