#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = -1;
    vector<char> prior[6] = {{'+','-','*'},
                              {'+','*','-'},
                              {'-','*','+'},
                              {'-','+','*'},
                              {'*','-','+'},
                              {'*','+','-'}};
    
    for(int k=0;k<6;k++){
        string strnum = "";
        long long num;
        vector<long long> nums;
        vector<char> giho;
        
        for(int i=0;i<expression.length();i++){
            if('0'<=expression[i]&&expression[i]<='9')
                strnum+=expression[i];
            else{
                nums.push_back(stoll(strnum));
                giho.push_back(expression[i]);
                strnum="";   
            }
        }
        nums.push_back(stoll(strnum));
        
        for(int i=0;i<3;i++){
            int j=0;
            while(j<giho.size()){
                if(prior[k][i]==giho[j]){
                    if(giho[j]=='+')
                        nums.insert(nums.begin()+j,nums[j]+nums[j+1]);
                    else if(giho[j]=='-')
                        nums.insert(nums.begin()+j,nums[j]-nums[j+1]);
                    else
                        nums.insert(nums.begin()+j,nums[j]*nums[j+1]);
                    
                    nums.erase(nums.begin()+j+1,nums.begin()+j+3);
                    giho.erase(giho.begin()+j,giho.begin()+j+1);
                    j=0;
                    continue;
                }
                j++;
            }
        }
        
        answer = max(answer,abs(nums[0]));     
    }   
    
    return answer;
}