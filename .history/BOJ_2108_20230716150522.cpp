#include "bits/stdc++.h"
using namespace std;

int max_num, min_num, scope;

int get_idx(int num) {
    return num - min_num;
}

int get_average(vector<int>& numbers, int N) {
    int sum = 0;
    for (int i=0; i<N; i++)
        sum += numbers[i];

    float avg = sum / N;
    int avg_i = (int)(sum/N);
    if (avg - avg_i >= 0.5) {
        return avg_i + 1;
    } else 
        return avg_i;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, AVG, CV, MCN;
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
    // Get the maximum count.
    int max_cnt = 0;
    vector<int> max_cnt_num;
    for (int i=0; i<scope+1; i++) {
        if (count[i].second > max_cnt) 
            max_cnt = count[i].second;
    }
    // Find the numbers that has max count
    for (int i=0; i<scope+1; i++) {
        if (count[i].second == max_cnt) {
            max_cnt_num.push_back(count[i].first);
        }
    }
    sort(numbers.begin(), numbers.end());
    if (max_cnt_num.size() > 1) {
        sort(max_cnt_num.begin(), max_cnt_num.end());
        MCN = max_cnt_num[1];
    } else 
        MCN = max_cnt_num[0];
    
    CV = numbers[(int)(N/2)];
    AVG = get_average(numbers, N);

    cout << AVG << '\n';
    cout << CV << '\n';
    cout << MCN << '\n';
    cout << scope << '\n';
}