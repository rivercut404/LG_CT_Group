#include "bits/stdc++.h"
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    vector<int> caps(N);
    for (int i=0; i<N; i++)
        cin >> caps[i];

    sort(caps.begin(), caps.end());

    int max_w = caps.back();
    for (int i=1; i<N; i++) {
        int weight = (i+1) * (caps[N-1-i]);
        if (weight > max_w) max_w = weight;
    }

    cout << max_w;
}