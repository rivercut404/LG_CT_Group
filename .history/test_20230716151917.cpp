#include "bits/stdc++.h"
using namespace std;

int test[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    float a = 9 / 5;
    int a_i = (int)a;

    cout << a << '\n';
    
    if (a - a_i <= -0.5) {
        cout << a_i - 1;
    } else 
        cout << a_i;
}