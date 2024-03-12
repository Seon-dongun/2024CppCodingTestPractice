#include <string>
#include <vector>
using namespace std;

int one = 0;
int zero = 0;

void start(vector<vector<int>>& arr,int len,pair<int,int> loc){
    if(len==1){
        if(arr[loc.first][loc.second]==0)
            zero++;
        else
            one++;
        return;
    }
  
    int otmp = 0;
    int ztmp = 0;
    for(int i=loc.first;i<loc.first + len;i++){
        for(int j=loc.second;j<loc.second + len;j++){
            if(arr[i][j]==1)
                otmp++;
            else
                ztmp++;
        }
    }
    
    if(otmp==len*len)
        one++;
    else if(ztmp==len*len)
        zero++;
    else{
        pair<int,int> locations[4] = {{loc.first,loc.second},{loc.first,loc.second + len/2},{loc.first+len/2,loc.second},{loc.first+len/2,loc.second + len/2}};
        for(int i=0;i<4;i++)
            start(arr,len/2,locations[i]);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int len = arr.size();
    start(arr,len,{0,0});
         
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}