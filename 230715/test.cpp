#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c, rot;
    cin >> c;

    rot = 'a' + ((c+13-'a') % 26);
    cout << rot;
}