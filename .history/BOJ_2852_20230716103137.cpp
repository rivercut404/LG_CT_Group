#include "bits/stdc++.h"
using namespace std;

class time 
{
public:
    int minute;
    int second;
    
public: 
    time(string t) {
        minute = stoi((string)(t[4]+t[3]));
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