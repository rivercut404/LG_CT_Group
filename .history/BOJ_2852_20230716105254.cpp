#include "bits/stdc++.h"
using namespace std;

class Time 
{
public:
    int minute;
    int second;
    
public: 
    Time() {}
    Time(string t) {
        minute = 10*(int)(t[4]-'0') + (int)(t[3]-'0');
        second = 10*(int)(t[1]-'0') + (int)(t[0]-'0');
    }

    const Time operator-(const Time &T) const {
        Time R;
        if (second >= T.second) 
            R.second = second - T.second;
        
        
    }
};

class Game 
{
public:
    int leader;

};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}