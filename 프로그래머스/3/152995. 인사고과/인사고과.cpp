#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]+a[1] >b[0]+b[1])
        return true;
    else if(a[0]+a[1] <b[0]+b[1])
        return false;
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<int> wanho(scores[0]);
    vector<int> incent(scores.size(),1);
    sort(scores.begin(),scores.end(),cmp);
    
    int tmp = scores[0][0]+scores[0][1];

    for(int i=0;i<scores.size();i++){   
        if(scores[i] == wanho)
            break;
        
        for(int j=0;j<i;j++){           
            if(scores[j][0]+scores[j][1] - scores[i][0]+scores[i][1] < 2)
                break;
            
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]){
                incent[i] = 0;
                break;
            }
        }   
    }
    
    int order = 0;
    for(int i=0;i<scores.size();i++){
        order += incent[i];
        
        if(scores[i][0] > wanho[0] && scores[i][1] > wanho[1])
            return -1;
        
        if(scores[i] == wanho)
            return order;        
    }   
}

