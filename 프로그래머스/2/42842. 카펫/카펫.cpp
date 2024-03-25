#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int check = yellow+brown;
    int i=3;
    while(i>=3){
        for(int j=3; j<=i;j++){
            if(i*j == check && ((i-2)*(j-2) == yellow) && (2*i + 2*j + -4 == brown)){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
        i++;
    }
}

// x-2 * y-2 = yellow => xy - 2y - 2x +4 = yellow
// x*2 + (y-2)*2 = brown => - 2x - 2y+4 = - brwon

//xy - 2y -2x +4 = yellow => xy - brown = yellow => xy = yellow + brwon;

