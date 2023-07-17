#include "bits/stdc++.h"
using namespace std;

class time 
{
public:
    int minute;
    int second;
    
public: 
    time(string t) {
        minute = 10*(int)(t[4]-'0') + (int)(t[3]-'0');
    }
};

class game 
{
public:
    int leader;

};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}