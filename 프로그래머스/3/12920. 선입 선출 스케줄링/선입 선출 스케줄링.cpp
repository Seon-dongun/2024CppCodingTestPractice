#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    long long time = 0;
    
    if(n - cores.size() <= 0)
        return n;
    
    long long high = 21000000000;
    long long low = 0;
    while(high >= low)	//n값보다 적게 작업을 진행하는 시간의 최대값을 구함
    {
        long long mid = (high+low)/2;
        time = cores.size();
        for(int i = 0; i < cores.size(); i++)
        {
            time += mid / cores[i];
            if(time >= n)
                break;
        }
        
        if(time >= n)
            high = mid - 1;
        else
            low = mid + 1;            
        
    }
    
    // n값보다 적게 작업을 진행하는 시간의 최대값일 때, 수행 가능한 작업 수 계산   
    // high 시간 경과했을 때, n값보다 적게 작업을 진행하는 시간의 최대값이다.
    time = cores.size();
    for(int i = 0; i < cores.size(); i++)
        time += high / cores[i];
    
    
    // high+1 시간 경과하는 사이클에서, n번째 작업을 처리하는 코어를 알 수 있다.
    for(int i = 0; i < cores.size(); i++)
    {
        if((high+1) % cores[i] == 0)
            time++;
        if(time == n)
            return i+1;
    }
    
    return answer;
}