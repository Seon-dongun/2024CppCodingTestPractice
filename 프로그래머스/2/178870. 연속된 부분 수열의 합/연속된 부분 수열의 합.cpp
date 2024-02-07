#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    int s=0,e=0;
    int sum=sequence[0];
    int minLength = sequence.size()+1;
    
    while(s<=e&& e<sequence.size()){
        if(sum<k){
            e++;
            sum+=sequence[e];
        }
        else if(sum==k){
            if(e-s+1<minLength){
                minLength = e-s+1;
                answer[0] = s;
                answer[1] = e;
            }

            sum-=sequence[s];
            s++;        
        }
        else{
            sum-=sequence[s];
            s++;
        }  
    } 
        
    return answer;  
}