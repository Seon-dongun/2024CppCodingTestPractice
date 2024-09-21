#include <string>
#include <vector>

using namespace std;

int arr[360010]; // 3600 * 99 + 60 * 59 + 59 -> 최대 재생 시간

int time_to_sec(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    
    return 3600*h + 60*m + s;
}

string time_tostring(int t) {
    string ret = "";
    
    int h = t / 3600; t %= 3600;
    int m = t / 60;
    int s = t % 60;
    
    ret += h >= 10 ? to_string(h) : ("0" + to_string(h));
    ret += ":";
    ret += m >= 10 ? to_string(m) : ("0" + to_string(m));
    ret += ":";
    ret += s >= 10 ? to_string(s) : ("0" + to_string(s));
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int END = time_to_sec(play_time);
    int ADV = time_to_sec(adv_time);
    
    int answer = 0;
    long long sum = 0;
    
    for(string log: logs) {
        int t1 = time_to_sec(log.substr(0, 8));
        int t2 = time_to_sec(log.substr(9));
        
        arr[t1]++;
        arr[t2]--;
    }
    // 누적합 계산
    for(int i=0; i<END-1; ++i) 
        arr[i+1] += arr[i];
    
    // 공익광고 재생시간 윈도우 
    for(int i=0; i<ADV; ++i) 
        sum += arr[i];

    long long max_sum = sum;
    for(int i=ADV; i<END; ++i) {
    	// 한 칸씩 슬라이딩하면서 sum 계산
        sum -= arr[i-ADV];
        sum += arr[i];
        
        if(sum > max_sum) {
            max_sum = sum;
            answer = i - ADV + 1;
        }
    }
    
    return time_tostring(answer);
}