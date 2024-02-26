#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int div = elements.size();
    unordered_set<int> s;
    
    for(int i=0;i<elements.size();i++){
        
        for(int j=0;j<elements.size();j++){
            int sum=0;
            for(int k=j;k<=j+i;k++){
                sum+=elements[k%div];
            }
            
            s.insert(sum);
        }
        
    }
    
    return s.size();
}