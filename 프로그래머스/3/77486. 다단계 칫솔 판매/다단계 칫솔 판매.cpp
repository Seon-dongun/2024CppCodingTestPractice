#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int n = enroll.size();
    unordered_map<string,int> benefit;
    unordered_map<string,string> parentInfo;
    
    for(int i=0;i<n;i++){
        parentInfo.insert({enroll[i],referral[i]});
        benefit.insert({enroll[i],0});
    }
    
    for(int i=0;i<seller.size();i++){
        string startSeller = seller[i];
        int sellAmount = amount[i]*100;
        int divAmount = sellAmount*0.1;
        
        while(startSeller!="-"){
            benefit[startSeller] += (sellAmount - divAmount);
            if(divAmount==0)
                break;
            
            startSeller = parentInfo[startSeller];
            sellAmount = divAmount;
            divAmount = (int)(sellAmount*0.1);            
        }
    }
    
    for(auto tmp : enroll)
        answer.push_back(benefit[tmp]);
    
    return answer;
}