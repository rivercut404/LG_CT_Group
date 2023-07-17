#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> lead(N+1);
    lead[0] = 0;

    for (int i=1; i<=N; i++) {
        cin >> lead[i];
    }
}