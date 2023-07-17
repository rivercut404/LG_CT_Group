#include "bits/stdc++.h"
using namespace std;

vector<string> numbers;

bool compare (string a, string b) {
    int len_a = a.length();
    int len_b = b.length();

    if (len_a != len_b)
        return len_a < len_b;
    else {
        for (int i=len_a-2; i>=0; i--) {
            int a_digit = (int)(a[i] - '0');
            int b_digit = (int)(b[i] - '0');

            if (i == 0)
                return a_digit < b_digit;

            if (a_digit != b_digit)
                return a_digit < b_digit;
            else 
                continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string ln;
        cin >> ln; 
        int len = ln.length();

        string number = "";
        for (int i=len-1; i>=0; i--) {
            if (isdigit(ln[i])) {                    
                if (number == "")
                    number += ln[i];
                else if (ln[i] == '0') {
                }
                else  // non-zero decimal input 
                    number = ln[i] + number;

                if (i==0 && number !="")
                    numbers.push_back(number);
            }
            else if (!number.empty()) {
                numbers.push_back(number);
                number = "";
            }
        }
    }
    sort(numbers.begin(), numbers.end(), compare);

    for (auto num : numbers) 
        cout << num << ' ';
}