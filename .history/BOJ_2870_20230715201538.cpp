#include "bits/stdc++.h"
using namespace std;

vector<int> numbers;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string ln;
        cin >> ln; 

        string number = "";
        for (int i=0; i<ln.length(); i++) {
            if (isdigit(ln[i])) 
                number += ln[i];
            else if (!number.empty()) {
                numbers.push_back(stoi(number));
            }
        }
    }
}