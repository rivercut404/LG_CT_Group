#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, B, C;
    int result = 0;
    cin >> N;

    vector<int> students(N);
    vector<int> students_b(N);
    vector<int> only_c(N);
    vector<int> with_b(N);

    for (int i=0; i<N; i++) 
        cin >> students[i];
    
    cin >> B;
    cin >> C;

    
    for (int i=0; i<N; i++) {
        // Calculate the result when only_c 
        only_c[i] = (students[i]%C == 0) ? (int)students[i]/C : (int)students[i]/C + 1;
        // Calculate the students with B
        students_b[i] = (students[i] > B) ? students[i] - B : 0;
        // Calculate the result with B
        with_b[i] = (students_b[i]%C == 0) ? (int)students_b[i]/C : (int)students_b[i]/C + 1;
        // Get the difference between with_b and only_c by reusing students_b
        students_b[i] = only_c[i] - with_b[i];
    }        
    
    int max_diff = 0; 
    int best_idx;

    for (int i=0; i<N; i++) {
        if (students_b[i] > max_diff) {
            best_idx = i;
            max_diff = student_b[i];
        }
    }

    for (int i=0; i<N; i++) {
        if (i == best_idx) {
            result += with_b[i];
            result -= only_c[i];
        }
        result += only_c[i];
    }

    cout << result;
}