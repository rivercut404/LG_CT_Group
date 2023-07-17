#include "bits/stdc++.h"
using namespace std;

vector<string> numbers;

void trunc_zero(string num) {
    int i = 0;
    while (num[i] == '0')
}

bool compare (string a, string b) {
    int len_a = a.length();
    int len_b = b.length();


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
                    number = ln[i] + number;
                else if (ln[i] == '0') 
                    continue;
            }
            else if (!number.empty()) {
                numbers.push_back(stoi(number));
                number = "";
            }
        }
    }

    sort(numbers.begin(), numbers.end());

    for (int num : numbers) 
        cout << num << '\n';
}