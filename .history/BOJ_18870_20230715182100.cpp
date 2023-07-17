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

    vector<int> points (N);
    vector<int> norm_points (N);
    // vector< pair<int, int> > points(N);
    // vector<int> result(N);

    // for (int i=0; i<N; i++) {
    //     points[i].first = i;
    //     cin >> points[i].second;
    // }
    for (int i=0; i<N; i++) 
        cin >> points[i];
    
    int min_p = *min_element(points.begin(), points.end());
    
    for (int i=0; i<N; i++) 
        norm_points[i] = (min_p < 0) ? points[i] - min_p : points[i];
    
    int max_p = *max_element(norm_points.begin(), norm_points.end());
    
    vector<int> count (max_p+1, 0);

    // Do count sort
    for (int i=0; i<N; i++) 
        count[norm_points[i]]++;
    
    vector<bool> is_point (max_p+1, false);
}