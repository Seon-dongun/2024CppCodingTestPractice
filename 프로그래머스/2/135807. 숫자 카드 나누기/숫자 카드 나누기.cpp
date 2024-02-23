#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int check(vector<int>& arrayA, vector<int>& arrayB){
    int maxV = max(*max_element(arrayA.begin(),arrayA.end()),*max_element(arrayB.begin(),arrayB.end()));
    int result=0;

    for(int i=2;i<=maxV;i++){
        int tmp=1;
        
        for(int j=0;j<arrayA.size();j++){
            if(arrayA[j]%i!=0 || arrayB[j]%i==0){
                tmp = 0;
                break;
            }
        }
        
        if(tmp!=1){
            tmp = 1;
            for(int j=0;j<arrayA.size();j++){
                if(arrayA[j]%i==0 || arrayB[j]%i!=0){
                    tmp = 0;
                    break;
                }
            }  
            
            if(tmp==1){
                if(result<i)
                    result = i;
            }

            
        }
        else{
            if(result<i)
                result = i;
        }    
        
    }
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    answer = check(arrayA,arrayB);
    
    return answer;
}