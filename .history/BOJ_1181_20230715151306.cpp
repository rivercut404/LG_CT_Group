#include "bits/stdc++.h"
using namespace std;

bool compare(string a, string b) {
    for (int i=0; i<a.length(); i++) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<vector<string>> v_words (51);

    cin >> N;

    while (N--)
    {
        string word;
        cin >> word;

        v_words[word.length()].push_back(word);
    }

    for (int i=1; i<51; i++) {
        if (!v_words[i].empty()) {
            sort()
        }
    }
}