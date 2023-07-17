#include "bits/stdc++.h"
using namespace std;

vector<int> numbers;

bool compare (string a, string b) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string ln;
        cin >> ln; 
        int len = ln.length();

        string number = "";
        for (int i=0; i<len; i++) {
            if (isdigit(ln[i])) {
                number += ln[i];
                if (i == len-1) 
                    numbers.push_back(stoi(number));
            }
            else if (!number.empty()) {
                numbers.push_back(stoi(number));
                number = "";
            }
        }
    }

    sort(numbers.begin(), numbers.end());

    for (int num : numbers) 
        cout << num << '\n';
}