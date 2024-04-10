#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    char alter[3] = {'4','1','2'};
    
    while(n>0){
        answer += alter[n%3];
        if(n%3==0)
            n = n/3 -1;
        else
            n/=3;
    }
    reverse(answer.begin(),answer.end());
    
    return answer;
}
/*
1 - 1   1
2 - 2   2
3 - 10  4
4 - 11  11
5 - 12  12
6 - 20  14
7 - 21  21
8 - 22  22
9 - 100 41
10 - 101    41
11 - 102    42
12 - 110    44
13 - 111    111
14 - 112    112
15 - 120    114

11 - 42
12 - 44
13 - 111
14 - 112
15 - 114
16 - 121
17 - 122
18 - 124

*/