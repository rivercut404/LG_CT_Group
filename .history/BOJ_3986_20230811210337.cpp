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
        while (hd < tl) {
            // forward truncate by using hd
            if (word[hd] == word[hd+1]) hd += 2;
            // backward truncate by using tl 
            else if (word[tl] == word[tl-1]) tl -= 2;
            // truncate by using both hd, tl
            else if (word[hd] == word[tl]) {
                hd++; tl--;
            }
        }
    }
}