#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int result = 0;

    cin >> N;

    while (N--) {
        string word;
        deque<char> deq;
        cin >> word;
        int len = word.length();

        for (char c : word)
            deq.push_back(c);

        
        if (len == 0)
            result++;
    }

    cout << result;
}