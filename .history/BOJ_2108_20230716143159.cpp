#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i=0; i<N; i++) 
        cin >> numbers[i];
    
    int max_num = *max_element(numbers.begin(), numbers.end());
    int min_num = *min_element(numbers.begin(), numbers.end());

    int scope = max_num - min_num;

    // Use count sort 
    vector< pair<int, int> > count(scope+1);
}