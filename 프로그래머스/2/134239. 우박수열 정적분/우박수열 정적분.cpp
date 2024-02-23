#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> dot;
    vector<double> vol;
    
    int i=0;
    int cnt=0;
    dot.push_back(k);
    while(k>1){
        if(k%2==0)
            k/=2;
        else
            k = k*3 +1;  
        dot.push_back(k);
        cnt++;
    }

    vol.push_back(0);
    
    double high = max(dot[0],dot[1]);
    double low = min(dot[0],dot[1]);
        
    vol.push_back(low + (high-low)/2);
    
    for(int i=1;i<cnt;i++){
        double high = max(dot[i],dot[i+1]);
        double low = min(dot[i],dot[i+1]);
        
        vol.push_back(vol[i] + (low + (high-low)/2));       
    }
    
    
    for(int i=0;i<ranges.size();i++){
        if(abs(ranges[i][1])+ranges[i][0]>=cnt+1){
            answer.push_back(-1.0);
        }
        else{
            answer.push_back(vol[cnt + ranges[i][1]] - vol[ranges[i][0]]);
        }
    }

    
    return answer;
}