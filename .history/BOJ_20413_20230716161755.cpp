#include "bits/stdc++.h"
using namespace std;

int std[4];

int get_2n_month_fee(stack<char>& grade) {
    int fee = 0;
    while (!grade.empty()) {
        if (grade.top() == 'D') {
            fee += grade.size() * std[3];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}