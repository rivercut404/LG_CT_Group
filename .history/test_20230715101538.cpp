#include "bits/stdc++.h"
using namespace std;

char vow[] = "aeiou";

bool is_vowel(char c) {
    for (int i=0; i<5; i++) {
        if (vow[i] == c)
            return true;
        
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c, rot;
    cin >> c;

    rot = 'a' + ((c+13-'a') % 26);
    cout << rot;
}