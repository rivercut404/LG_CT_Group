#include "bits/stdc++.h"
using namespace std;

bool compare(string a, string b) {
    for (int i=0; i<a.length(); i++) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
        else
            continue;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector< vector<string> > v_words (51);

    cin >> N;

    while (N--)
    {
        bool contained = false;
        string word;
        cin >> word;
        int len = word.length();
        
        for (int i=0; i<v_words[len].size(); i++) {
            if (word == v_words[len][i])
                contained = true;
        }

        v_words[len].push_back(word);
    }

    for (int i=1; i<51; i++) {
        if (!v_words[i].empty()) {
            sort(v_words[i].begin(), v_words[i].end(), compare);
        }
    }

    for (int i=1; i<51; i++) {
        if (!v_words[i].empty()) {
            for (string str : v_words[i])
                cout << str << '\n';
        }
    }
}