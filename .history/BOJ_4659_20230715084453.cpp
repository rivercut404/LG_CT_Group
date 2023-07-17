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
        bool has_vowels = false;
        bool is_acc = true;
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

                // 1. two same char BAN except ee oo 
                if (c1 == c2) {
                    if (c1 != 'e' && c1 != 'o') {
                        is_acc = false;
                        break;
                    }
                }
            }
            checking.push_back(pw_stack.top());
            pw_stack.pop();
        }
    } while (pw != "end");
}