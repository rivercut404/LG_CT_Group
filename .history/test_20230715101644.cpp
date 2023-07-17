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

    string pw;
    bool has_vowels = false;
    cin >> pw;

    for (int i=0; i<pw.length(); i++) {
        if (is_vowel(pw.at(i))) {
            has_vowels = true;
            break;
        }
    }

    if (!has_vowels) {
        cout << '<' << pw << '>' << " is not acceptable 1\n";
    }
}