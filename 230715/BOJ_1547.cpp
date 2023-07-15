#include "bits/stdc++.h"
using namespace std;

int cup_numbers[4] = {0, 1, 2, 3};

int get_idx(int num) {
    for (int i=1; i<4; i++) {
        if (cup_numbers[i] == num)
            return i;
    }
}

void swap(int a, int b) {
    int i = get_idx(a);
    int j = get_idx(b);
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
    }
    
    cout << cup_numbers[1];
}