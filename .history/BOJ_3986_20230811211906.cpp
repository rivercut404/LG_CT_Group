#include "bits/stdc++.h"
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int nice = 0;
    while (N--) {
        string word; cin >> word;
        int hd = 0; int tl = word.length() - 1;
        for (int i=0; i<(int)(word.length()/2)+1; i++) {
            if (hd == word.length()-1) hd = 0;
            // forward truncate by using hd
            if (word[hd] == word[hd+1]) hd += 2;
            // backward truncate by using tl 
            else if (word[tl] == word[tl-1]) tl -= 2;
            // truncate by using both hd, tl
            else if (word[hd] == word[tl]) {
                hd++; tl--;
            }
        }

        if (hd > tl) {
            nice++;
            cout << word << '\n';
        }
    }

    cout << nice;
}