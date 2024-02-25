#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> A;
    map<int,int> B;
    for(int i=0;i<topping.size();i++){
        if(A.find(topping[i]) == A.end())
            A.insert({topping[i],1});
        else
            A[topping[i]]++;
    }
    
    for(int i=0;i<topping.size();i++){
        if(A.find(topping[i])!=A.end()){
            A[topping[i]]--;
            if(A[topping[i]]==0)
                A.erase(topping[i]);
            
            if(B.find(topping[i]) == B.end())
                B.insert({topping[i],1});
            else
                B[topping[i]]++;      
        }
           
        if(A.size()==B.size())
            answer++;
    }
  
    return answer;
}