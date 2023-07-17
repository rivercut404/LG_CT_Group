#include "bits/stdc++.h"
using namespace std;

class Time 
{
public:
    string minute;
    string second;
    
public: 
    Time() {}
    Time(string t) {
        minute = t[4] + t[3];
        second = t[1] + t[0];
    }

    const Time operator-(const Time &T) const {
        Time R;
        if (stoi(second) >= T.second) 
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