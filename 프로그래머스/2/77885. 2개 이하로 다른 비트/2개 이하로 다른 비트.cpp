#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
   vector<long long> answer;
    for (long long number : numbers)
    {
        if(number%2==0){
            answer.push_back(number+1);
            continue;
        }
        
        long long bit = 1;
        while ((number & bit) > 0)
            bit <<= 1;   
        answer.push_back(number + (bit >> 1));        
    }
    return answer;
}
