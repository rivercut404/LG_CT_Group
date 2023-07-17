#include "bits/stdc++.h"
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector< pair<int, int> > points(N);
    vector<int> result(N);

    for (int i=0; i<N; i++) {
        points[i].first = i;
        cin >> points[i].second;
    }

    sort(points.begin(), points.end(), compare);
    
    for (int i=0; i<N; i++) {
        result[points[i].first] = i;
    }

    for (int i=0; i<N-1; i++) {
        if (points[i].second == points[i+1].second)
    }
}