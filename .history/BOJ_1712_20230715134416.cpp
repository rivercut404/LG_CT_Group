#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    int point;

    cin >> A;
    cin >> B;
    cin >> C;

    if (B >= C) 
        cout << -1;
    else {
        point = ((int)(A / (C-B))) + 1;
        cout << point;
    }
}