#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string rot = "";

    getline(cin, str);
    
    for (char c : str) {
        if (c >= 'a' && c <= 'z')
            rot += 'a' + ((c+13-'a') % 26);
        else if(c >= 'A' && c <= 'Z')
            rot += 'A' + ((c+13-'A') % 26);
        else 
            rot += c;
    }
    
    cout << rot;
}