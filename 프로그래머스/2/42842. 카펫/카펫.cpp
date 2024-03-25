#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i=3;
    while(1){
        for(int j=3; j<=i;j++){
            if(((i-2)*(j-2) == yellow) && (2*i + 2*j + -4 == brown)){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
        i++;
    }
}

// x-2 * y-2 = yellow 
// x*2 + (y-2)*2 = brown



