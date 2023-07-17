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
        bool has_vowels, is_acc = false;
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

                if 
            }
            
            pw_stack.pop();
        }
    } while (pw != "end");
}