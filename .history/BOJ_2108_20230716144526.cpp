#include "bits/stdc++.h"
using namespace std;

int max_num, min_num, scope;

int get_idx(int num) {
    return num - min_num;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i=0; i<N; i++) 
        cin >> numbers[i];
    
    max_num = *max_element(numbers.begin(), numbers.end());
    min_num = *min_element(numbers.begin(), numbers.end());

    scope = max_num - min_num;

    // Use count sort 
    vector< pair<int, int> > count(scope+1); 
    // Initialize the count values
    for (int i=0; i<scope+1; i++) {
        count[i].first = min_num + i;  // value
        count[i].second = 0;  // count
    }
    // Set the counting vector
    for (int i=0; i<N; i++) {
        count[get_idx(numbers[i])].second++;
    }
    // Get the maximum freq.
    int max_freq = 0;
    vector<int> most_appeared;
}