#include "bits/stdc++.h"
using namespace std;

int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name; 
    cin >> name;

    for (char c : name)
        freq[c - 'A']++;
}