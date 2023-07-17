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
        bool accepted = true;
        stack<char> pw_stack;
        vector<char> checking;
        cin >> pw;

        for (int i=0; i<pw.length(); i++) {
            if (is_vowel(pw[i])) {
                has_vowels = true;
                break;
            }
        }

        if (!has_vowels) {
            cout << '<' << pw << '>' << " is not acceptable\n";
            continue;
        }

        for (char c : pw)
            pw_stack.push(c);

        while (!pw_stack.empty()) {
            if (!checking.empty()) {
                char c1 = checking.back();
                char c2 = pw_stack.top();
                
                if (is_vowel(c1) != is_vowel(c2)) {
                    checking.clear();
                    checking.push_back(c2);
                    pw_stack.pop();
                    continue;
                }
                // vow vow or cons cons 
                else if (checking.size() == 2) {
                    accepted = false;
                    break;
                } else if (c1 == c2) {
                    if (c1 != 'e' && c1 != 'o') {
                        accepted = false;
                        break;
                    }
                } 
            }
            checking.push_back(pw_stack.top());
            pw_stack.pop();
        }

        if (accepted) {} else {}
    } while (pw != "end");
}