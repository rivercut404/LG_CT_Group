#include "bits/stdc++.h"
using namespace std;

string vow = "aeiouxy";
string cons = "bcdfghjklmnpqrstvwz";

bool is_vowel(char c) {
    for (int i=0; i<7; i++) {
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