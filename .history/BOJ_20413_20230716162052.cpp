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
    int fee = 0;
    while (!grade.empty()) {
        if (grade.top() == 'D') {
            fee += grade.size() * std[3];
            break;
        } else {

        }
    }
    return fee;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}