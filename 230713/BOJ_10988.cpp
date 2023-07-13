#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int is_pal = 1;
    string word;

    cin >> word; 
    int len = word.length();

    for (int i=0; i<(int)len/2; i++) {
        if (word[i] != word[len-1-i])
            is_pal = 0;
    }

    cout << is_pal << '\n';
}