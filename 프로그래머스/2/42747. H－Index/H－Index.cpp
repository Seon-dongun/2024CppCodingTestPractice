#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i=0;i<citations.size();i++){
        int h = i+1;
        int flag1 = 0, flag2 = 1;
        int cnt1 = 0, cnt2 = 0;
        int s = 0,flag3=0;
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=h)
                cnt1++;      
            
            if(cnt1==1&&flag3==0){
                s = j;
                flag3 = 1;
            }
            
            if(cnt1==h)
                flag1=1;
        }
        
        if(flag1==1){
            for(int j=s-1;j>=0;j--){
                if(citations[j]>h){
                    flag2 = 0;
                    break;
                }
            }
            if(flag1 && flag2){
                answer = max(answer,h);
            }
            
        }
        
        
        
    }
    
    return answer;
}

//0 1 3 5 6