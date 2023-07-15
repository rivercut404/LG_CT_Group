#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int layers[100000]; 
    int i = 1;
    layers[1] = 1;

    cin >> N;
    
    while (layers[i] < N) {
        i++;
        layers[i] = layers[i-1] + 6*i -6;
    }

    cout << i;
}