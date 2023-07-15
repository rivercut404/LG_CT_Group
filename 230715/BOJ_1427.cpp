#include "bits/stdc++.h"
using namespace std;

bool compare(char a, char b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;

    cin >> N;

    sort(N.begin(), N.end(), compare);

    cout << N;
}