#include "bits/stdc++.h"
using namespace std;

int fee;
int trucks[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    // Get the prices
    cin >> A;
    cin >> B;
    cin >> C;
    
    for (int i=0; i<3; i++) {
        int begin, end;
        cin >> begin;
        cin >> end;

        for (int j=begin; j<end; j++) 
            trucks[j]++;
    }

    // Calculate the fee
    for (int i=1; i<101; i++) {
        if (trucks[i] == 0)
            continue;
        else if (trucks[i] == 1) 
            fee += A;
        else if (trucks[i] == 2) 
            fee += 2*B;
        else if (trucks[i] == 3) 
            fee += 3*C;
    }

    cout << fee << '\n';
}