#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size()); // prices 크기만큼 answer을 초기화 한다.
    stack<int> s;
    
    for(int i=0; i<prices.size()-1; i++){ // 마지막 price는 뭘해도 0초이니 제외하고 반복문 실행.
        while(!s.empty()&&prices[i]<prices[s.top()]){ // 하락장이라면
            answer[s.top()] = i-s.top(); // 기간은 현재 인덱스 i와 top()의 인덱스 차이가 된다.
            s.pop(); // top의 기간을 구했으니 pop.
        }
        s.push(i); // i를 push. 인덱스 i는 최고 가격이 된다.
    }
    
    /* 스택에 남은 원소들 처리 */
    while(!s.empty()){ // 스택에 남은 것들은 항상 상승만 했기에
        answer[s.top()] = (prices.size()-1)-s.top(); //맨 끝 위치에서 top을 빼줘서 끝까지 상승기간 구함. 
        s.pop();
    }
    answer[prices.size()-1]=0; // 마지막 price는 항상 0이 나옴.
    
    return answer;
}
