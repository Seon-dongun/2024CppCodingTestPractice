#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int result;
    string answer = "";
    
    sort(timetable.begin(),timetable.end());
    
    vector<int> timeTable;
    
     for (auto& time : timetable)
        timeTable.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
    
    int bus = 540;
    int idx = 0;
    
    for(int i=1;i<=n;i++){
        int cnt = 0;
        
        while(cnt < m && idx < timeTable.size())
        {
            if(bus >= timeTable[idx])
            {
                idx++;
                cnt++;
            }
            else
                break;
        }
        
        if(i==n)
        {
            if(cnt < m)
                result = bus;
            else
                result = timeTable[idx-1]-1;
        }
        
        bus += t;
    }
    
    int hours = result / 60;
    if (hours <= 9)
        answer = "0" + to_string(hours) + ":";
    else
        answer = to_string(hours) + ":";

    int minutes = result % 60;
    if (minutes <= 9)
        answer += "0" + to_string(minutes);
    else
        answer += to_string(minutes);
    
    return answer;
}