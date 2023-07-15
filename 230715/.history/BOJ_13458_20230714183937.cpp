#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, B, C;
    cin >> N;

    vector<int> students(N);
    vector<int> only_c(N);
    vector<int> with_b(N);

    for (int i=0; i<N; i++) 
        cin >> students[i];
    
    cin >> B;
    cin >> C;

    // Calculate the result when only_c 
    for (int i=0; i<N; i++) {
        only_c[i] = students[i]% == 0 ? (int)students[i]/C : (int)students[i]/C + 1;
    }
}