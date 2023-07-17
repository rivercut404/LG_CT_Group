#include "bits/stdc++.h"
using namespace std;

int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int odd_alpha = 0;
    string name; 
    cin >> name;

    for (char c : name)
        freq[c - 'A']++;

    for (int i=0; i<26; i++) {
        if (freq[i]%2 != 0)
            odd_alpha++;
    }
}