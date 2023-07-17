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
    if (min_p < 0) {
        for (int i=0; i<N; i++)
            norm_points[i] = points[i] + min_p;
    }

    int max_p = *max_element(points.begin(), points.end());

}