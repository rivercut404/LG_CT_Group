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
    string Get_Time_Str() {
        string time_str = "";
        string str_m = (minute > 10) ? to_string(minute) : '0' + to_string(minute);
        string str_s = (second > 10) ? to_string(second) : '0' + to_string(second);     
        time_str = str_m + ":" + str_s;
        return time_str;   
    
    }
    const Time operator-(const Time &T) const {
        Time R;
        if (second >= T.second) {
            R.second = second - T.second;
            R.minute = minute - T.minute;
        }
        else {
            R.second = second + 60 - T.second;
            R.minute = minute - 1 - T.minute;
        }
        return R;
    }
    const Time operator-(const Time &T) const {
        Time R;
        if (second >= T.second) {
            R.second = second - T.second;
            R.minute = minute - T.minute;
        }
        else {
            R.second = second + 60 - T.second;
            R.minute = minute - 1 - T.minute;
        }
        return R;
    }
};

class Game 
{
public:
    int leader, last_leader;
    Time lead_t[3];
    int score[3] = {0, 0, 0};
    // vector< pair<int, Time> > goal_t;

public:
    Game() {
        last_leader = 0;
        leader = 0;
        lead_t[1] = Time("00:00");
        lead_t[2] = Time("00:00");
    }
    void Goal(int team, Time t) {
        // Record the new goal to score
        score[team]++;
        // Check whether the leader is changed
        int new_leader = Check_Leader();
        if (last_leader != new_leader) {
            
        }
    }
    int Check_Leader() {
        if (score[1] > score[2])
            return 1;
        else if (score[2] > score[1])
            return 2;
        else 
            return 0;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}