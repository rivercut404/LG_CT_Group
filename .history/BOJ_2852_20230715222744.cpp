#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int score[] = {0, 0, 0};
    vector<int> scorer(N);
    vector<int> lead(N+1);
    lead[0] = 0;

    for (int i=0; i<N; i++) {
        cin >> scorer[i];
    }
    
    for (int i=0; i<N; i++) {
        score[scorer[i]]++;
        if (score[1] > score[2])
            lead[i+1] = 1;
        else if (score[1] < score[2])
            lead[i+1] = 2;
        else 
            lead[i+1] = 0;
    }
}