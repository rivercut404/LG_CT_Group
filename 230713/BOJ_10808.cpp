#include "bits/stdc++.h"
using namespace std;

int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;

    cin >> S;
    int len = S.size();

    for (int i=0; i<len; i++) {
        freq[S[i]-'a']++;        
    }    

    for (int i=0; i<26; i++) 
        cout << freq[i] << ' ';
}