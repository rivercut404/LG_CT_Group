#include "bits/stdc++.h"
using namespace std;

bool compare() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // pair<int, string> user;

    int N;
    cin >> N;
    
    vector< pair<int, string> > users(N);

    for(int i=0; i<N; i++) {
        cin >> users[i].first;
        cin >> users[i].second;
    }
}