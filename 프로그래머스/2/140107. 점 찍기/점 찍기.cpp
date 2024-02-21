#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int x=0;x<=d;x+=k){
        // d^2 = x^2 + y^2
        // y = sqrt(d^2-x^2)
        int maxY = sqrt((long long)d*d-(long long)x*x); // 고정된 x값에 대한 최대 y값을 구한다.
        answer += (maxY / k) + 1; 
        // 각각의 고정된 x값에서의 최대 y값을 통해서, 가능한 y값의 갯수를 구할 수 있게 된다. 이 때 최대y값을 좌표의 증가 추이인 k로 나누어주면, k의 배수이면서 최대 y값 이내의 가능한 모든 y좌표의 갯수를 구할 수 있다.
        // 주의할 점은 y좌표가 0인 (x,0)의 케이스는 최대y값을 k로 나누었을 때의 갯수에는 포함되지 않기 때문에 별도로 1을 더해주어야 한다.
    } 
    
    return answer;
}
