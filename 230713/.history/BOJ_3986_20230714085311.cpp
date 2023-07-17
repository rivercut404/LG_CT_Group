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

        while (len) {
            if (len%2 == 1) 
                break;

            // Check the head 
            if (deq[0] == deq[1]) {
                deq.pop_front();
                deq.pop_front();
                len -= 2;
            } else if (deq[len-1] == deq[len-2]) {
                // Check the tail
                deq.pop_back();
                deq.pop_back();
                len -= 2;
            } else if (deq.front() == deq.back()) {
                // Check start and end char
                deq.pop_front();
                deq.pop_back();
                len -= 2;
            } else 
                break;
        }

        if (len == 0)
            result++;
    }

    cout << result;
}