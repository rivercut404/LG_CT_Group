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

    string pw;

    do {
        bool has_vowels, accepted = false;
        stack<char> pw_stack;
        vector<char> checking;
        cin >> pw;

        for (char c : pw)
            pw_stack.push(c);

        while (!pw_stack.empty()) {
            if (checking.empty())
                checking.push_back(pw_stack.top());
            else {
                char c1 = checking.back();
                char c2 = pw_stack.top();
                
                if (is_vowel(c1) != is_vowel(c2)) {
                    
                }
                // two same char BAN except ee oo 
                else if (c1 == c2) {
                    if (c1 != 'e' && c1 != 'o') 
                        break;
                } 
            }
            checking.push_back(pw_stack.top());
        }
    } while (pw != "end");
}