#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int fibo[10000];
    int i = 0;

    fibo[0] = fibo[1] = 1;

    while (1) {
        fibo[i+2] = fibo[i] + fibo[i+1];
        if (fibo[i+2] > 10000000)
            break;
    }
}