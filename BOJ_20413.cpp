#include "bits/stdc++.h"
using namespace std;

int std_fee[4];

int grade_to_fee(char grade) {
    if (grade == 'B') {
        return std_fee[0] - 1;
    } else if (grade == 'S') 
        return std_fee[1] - 1;
    else if (grade == 'G')
        return std_fee[2] - 1;
    else if (grade == 'P')
        return std_fee[3] - 1;
    else 
        return std_fee[3];
}

int get_2n_month_fee(stack<char>& grade) {
    bool flag = false;
    int fee = 0;
    while (!grade.empty()) {
        if (grade.top() == 'D') {
            fee += grade.size() * std_fee[3];
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

    int N;
    int fee = 0;
    cin >> N;

    for (int i=0; i<4; i++) {
        cin >> std_fee[i];
    }

    string monthly_grade;
    cin >> monthly_grade;

    stack<char> grade_stack;

    for (int i=N-1; i>=0; i--) {
        grade_stack.push(monthly_grade[i]);
    }

    int months = grade_stack.size();
    if (months%2 == 0) {
        fee = get_2n_month_fee(grade_stack);
    } else {
        fee += grade_to_fee(grade_stack.top());
        grade_stack.pop();
        fee += get_2n_month_fee(grade_stack);
    }

    cout << fee;
}