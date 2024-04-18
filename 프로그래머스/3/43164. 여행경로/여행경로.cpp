#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> answer;
bool check[10001];
bool isAnswer;

void dfs(vector<vector<string>>& tickets,string start, int ticketCnt){
    answer.push_back(start);
    
    if (ticketCnt == tickets.size())
        isAnswer = true;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && !check[i]) {
            check[i] = true;
            cout << tickets[i][1] << " " << ticketCnt+1 << endl;
            dfs(tickets,tickets[i][1], ticketCnt+1);
            
            if (!isAnswer) {
                answer.pop_back();
                check[i] = false;
            }
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs(tickets,"ICN", 0);
    
    return answer;
}
