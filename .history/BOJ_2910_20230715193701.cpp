#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;

    cin >> N;
    cin >> C;

    vector<int> numbers(N);
    for (int i=0; i<N; i++)
        cin >> numbers[i];
    
    vector<int> freq(C+1, 0);

    for (int i=0; i<N; i++) {
        freq[numbers[i]]++;
    }

    // vector< pair<int, int> > val_freq;

    // Get the number that has non-zero freq.
    for (int i=0; i<=C; i++) {
        if (freq[i] > 0)
            
    }
}