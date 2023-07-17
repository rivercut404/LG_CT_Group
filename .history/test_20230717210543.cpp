#include "bits/stdc++.h"
using namespace std;

int test[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr(8, 0);

    vector< vector<int> > arr2(10, arr);

    for (int i=0; i<10; i++) {
        for (auto n : arr2[i])
            cout << n << ' ';
        cout << '\n';
    }
}