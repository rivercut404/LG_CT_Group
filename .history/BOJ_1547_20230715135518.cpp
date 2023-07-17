#include "bits/stdc++.h"
using namespace std;

int cup_numbers[4] = {0, 1, 2, 3};

int get_idx(int num) {
    
}

void swap(int i, int j) {
    int temp = cup_numbers[i];
    cup_numbers[i] = cup_numbers[j];
    cup_numbers[j] = temp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;

    cin >> M;

    while (M--) {
        int i, j;
        cin >> i;
        cin >> j;

        swap(i, j);

        for (int j=1; j<4; j++)
            cout << cup_numbers[j] << ' ';
    }
    cout << '\n';
    cout << cup_numbers[1];
}