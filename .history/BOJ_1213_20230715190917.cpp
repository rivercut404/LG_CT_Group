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

    string forward = "";
    string center = "";
    string backward = "";

    if (odd_alpha > 1)
        cout << "I'm Sorry Hansoo\n";
    else if (odd_alpha == 1) {
        for (char i=0; i<26; i++) {
            if (freq[i]%2 != 0)
                center = center + (char)('A' + i);
        }
    } else {
        for (char i=0; i<26; i++) {

        }
    }
}