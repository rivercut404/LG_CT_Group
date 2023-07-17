#include "bits/stdc++.h"
using namespace std;

string vow = "aeiou";
string cons = "bcdfghjklmnpqrstvwxyz";

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

    stack<char> password;
    vector<char> v;

    

}