#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long A, B, V;
    int did, days = 0;

    cin >> A;
    cin >> B;
    cin >> V;

    while (1) {
        days++;

        did += A;
        if (did >= V)
            break;
        else 
            did -= B;
    }

    cout << days;
}