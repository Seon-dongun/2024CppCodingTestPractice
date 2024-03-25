#include <string>
#include <vector>
#include <cmath>
#include <set> 
#include <algorithm>
using namespace std;

bool numCheck(int num){
    if(num<=1)
        return false;
    
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;         
    }
    return true;
}

int solution(string numbers) {
    vector<char> v;
    set<int> s;
    
    for(int i=0;i<numbers.length();i++)
        v.push_back(numbers[i]);
    
    sort(v.begin(),v.end());
    
    do{
        string tmp = "";
        for(int i=0;i<v.size();i++){
            tmp+=v[i];
            if(numCheck(stoi(tmp)))
                s.insert(stoi(tmp));
        }
        
    }while(next_permutation(v.begin(), v.end()));

    return s.size();
}
