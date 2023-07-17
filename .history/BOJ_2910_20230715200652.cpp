#include "bits/stdc++.h"
using namespace std;

bool compare(pair<int, int> a, pair<int,int> b) {
    return a.second > b.second;
}

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
    
    int appeared = 0;
    // Get the number that has non-zero freq.
    for (int i=0; i<=C; i++) {
        if (freq[i] > 0)
            appeared++;           
    }

    vector< pair<int, int> > val_freq (appeared);

    for (int i=0; i<=C; i++) {
        if (freq[i] > 0) {
            val_freq[i].first = i;
            val_freq[i].second = freq[i];
        }
    }

    sort(val_freq.begin(), val_freq.end(), compare);

    // for (int i=0; i<appeared; i++) {
    //     for (int j=0; j<val_freq[i].second; j++)
    //         cout << val_freq[i].first << ' ';
    // }
}