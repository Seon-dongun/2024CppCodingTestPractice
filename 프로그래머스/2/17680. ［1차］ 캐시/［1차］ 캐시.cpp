#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer=0;
    deque<string> cache;
    
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].length();j++)
            cities[i][j] = tolower(cities[i][j]);
    }
    
    if(cacheSize==0)
        return 5*cities.size();
    
    for(int i=0;i<cities.size();i++){        
        int idx;
        bool cacheHM = false;
        
        for(int j=0;j<cache.size();j++){
            if(cache[j]==cities[i]){
                idx = j;
                cacheHM = true;
                break;
            }
        }
        
        if(cacheHM){
            cache.erase(cache.begin()+idx);
            cache.push_back(cities[i]);
            answer+=1;
        }
        
        else{
            answer+=5;
            cache.push_back(cities[i]);
            if(cache.size() > cacheSize)
                cache.pop_front();  
        }  
    }
    
    return answer;
}