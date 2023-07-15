#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, B, C;
    cin >> N;

    vector<int> students(N);
    vector<int> students_b(N);
    vector<int> only_c(N);
    vector<int> with_b(N);

    for (int i=0; i<N; i++) 
        cin >> students[i];
    
    cin >> B;
    cin >> C;

    // Calculate the result when only_c 
    for (int i=0; i<N; i++) {
        only_c[i] = (students[i]% == 0) ? (int)students[i]/C : (int)students[i]/C + 1;
    }

    // Calculate the students with B
    for (int i=0; i<N; i++) {
        students_b[i] = (students[i] > B) ? students[i] - B : 0;
    }

    // Calculate the result with B
    for (int i=0; i<N; i++)
        with_b[i] = (students_b[i]% == 0) ? (int)students_b[i]/C : (int)students_b[i]/C + 1;

    // Get the difference between with_b and only_c by reusing students_b
    for (int i=0; i<N; i++) 
        students_b[i] = only_c[i] - with_b[i];
}