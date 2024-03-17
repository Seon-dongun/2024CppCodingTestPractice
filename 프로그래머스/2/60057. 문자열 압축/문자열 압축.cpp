#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int i=1;
    string minStr = "A";
    if(s.length()==1)
        return 1;
    
    while(i<=s.length()/2){
        string last = "";
        string minTmpStr = "";
        int cnt,j=0;
        for(;j<s.length();j+=i){
            string tmp = "";
            for(int k=j;k<j+i&&k<s.length();k++)
                tmp+=s[k];
            
            if(last==""){
                last = tmp;
                cnt=1;
            }
            else if(last==tmp)
                cnt++;              
            else{
                if(cnt!=1)
                    minTmpStr += to_string(cnt);
                minTmpStr += last;
                
                last = tmp;
                cnt = 1;
            }

        }
        if(cnt!=1)
            minTmpStr += to_string(cnt);
        minTmpStr += last;
        

        if(minStr=="A" || minStr.length() > minTmpStr.length())
            minStr = minTmpStr;

        i++;
    }
    return minStr.length();
}
