#include "bits/stdc++.h"
using namespace std;

int players[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        string name;
        cin >> name; 

        players[name.front()-'a']++;
    }

    string res = "";

    for (char i=0; i<26; i++) {
        if (players[i] > 4) 
            res += 'a' + i;
    }

    if (res.empty()) 
        cout << "PREDAJA\n";
    else
        cout << res;
}