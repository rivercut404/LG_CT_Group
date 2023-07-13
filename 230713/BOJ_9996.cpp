#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string pattern;

    cin >> N;
    cin >> pattern;

    while (N--) {
        int i = 0;
        bool equality = true;
        string name;
        deque<char> deq_p;
        deque<char> deq_n;
        
        cin >> name; 

        for (char c : pattern) 
            deq_p.push_back(c);

        for (char c : name) 
            deq_n.push_back(c);

        if (name.length() < pattern.length()-1) {
            cout << "NE\n";
            continue;
        }

        while (isalpha(deq_p.front())) {
            if (deq_p.front() != deq_n.front()) {
                cout << "NE\n";
                equality = false;
                break;
            } else {
                deq_p.pop_front();
                deq_n.pop_front();
            }
        }

        if (!equality)
            continue;

        while (isalpha(deq_p.back())) {
            if (deq_p.back() != deq_n.back()) {
                cout << "NE\n";
                equality = false;
                break;
            } else {
                deq_p.pop_back();
                deq_n.pop_back();
            }
        }

        if (equality && deq_p.front() == '*' && deq_p.back() == '*') 
            cout << "DA\n";
    }
}