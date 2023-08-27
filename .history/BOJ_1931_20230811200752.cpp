#include "bits/stdc++.h"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector< pair<int,int> > meetings(N);
    // pair: {end_T, start_T}
    for(int i=0; i<N; i++)
        cin >> meetings[i].second >> meetings[i].first;
    
    sort(meetings.begin(), meetings.end());

    int answer = 0;
    for (auto meeting : meetings) {

    }
}