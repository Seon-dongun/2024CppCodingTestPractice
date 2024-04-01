#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i=0;i<arr.size()-1;i++){
        answer = lcm(arr[i],arr[i+1]);
        arr[i+1] = answer;
    }
    return answer;
}
