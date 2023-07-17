#include "bits/stdc++.h"
using namespace std;

int std[4];

int grade_to_fee(char grade) {
    if (grade == 'B') {
        return std[0] - 1;
    } else if (grade == 'S') 
        return std[1] - 1;
    else if (grade == 'G')
        return std[2] - 1;
    else if (grade == 'P')
        return std[3] - 1;
    else 
        return std[3];
}

int get_2n_month_fee(stack<char>& grade) {
    bool flag = false;
    int fee = 0;
    while (!grade.empty()) {
        if (grade.top() == 'D') {
            fee += grade.size() * std[3];
            break;
        } else if (!flag) {
            // odd number month
            grade.pop();
            flag = true;
        } else if (flag) {
            // even number month
            fee += grade_to_fee(grade.top());
            grade.pop();
            flag = false;
        }
    }
    return fee;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, fee;
    cin >> N;

    for (int i=0; i<4; i++) {
        cin >> std[i];
    }

    string monthly_grade;
    cin >> monthly_grade;

    stack<char> grade_stack;

    for (int i=0; i<N; i++) {
        grade_stack.push(monthly_grade[i]);
    }

    int months = grade_stack.size();
    if (months%2 == 0) {
        cout << get_2n_month_fee(grade_stack);
    } else {

    }
}