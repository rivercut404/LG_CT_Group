#include "bits/stdc++.h"
using namespace std;

int test[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> g;

    g.push_back(9);
    g.push_back(2.5);
    g.push_back(12);
    g.push_back(12);
    g.push_back(12);

    g.push_back(13.5);
    g.push_back(13.5);
    g.push_back(4);
    g.push_back(13.5);
    g.push_back(13.5);
    g.push_back(13.5);

    g.push_back(13.5);
    g.push_back(3.5);

    g.push_back(12);
    g.push_back(3);
    g.push_back(7.5);
    g.push_back(12);
    g.push_back(10.5);

    g.push_back(9);
    g.push_back(13.5);
    g.push_back(13.5);
    g.push_back(13.5);

    g.push_back(12);
    g.push_back(7.5);
    g.push_back(10.5);
    g.push_back(12);
    g.push_back(13.5);

    int sum = 0;
    for (int a : g) 
        sum += a;

    cout << sum << ' ' << sum/73;
}