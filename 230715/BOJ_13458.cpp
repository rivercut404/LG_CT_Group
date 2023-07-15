#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, B, C;
    cin >> N;
    int result = N;

    vector<int> students(N);
    vector<int> students_b(N);
    vector<int> with_b(N);

    for (int i=0; i<N; i++) 
        cin >> students[i];
    
    cin >> B;
    cin >> C;


    for (int i=0; i<N; i++) {
        // Calculate the students with B
        students_b[i] = (students[i] > B) ? students[i] - B : 0;
        // Calculate the result with B
        with_b[i] = (students_b[i]%C == 0) ? (int)students_b[i]/C : (int)(students_b[i]/C) + 1;
    }        

    for (int i=0; i<N; i++) 
        result += with_b[i];

    cout << result;
}