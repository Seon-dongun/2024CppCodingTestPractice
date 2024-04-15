#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> kind;
    for (int i = 0; i < gems.size(); ++i)
        kind.insert(gems[i]); // set은 중복을 제거하므로 최종적으로 kind.size() 는 보석의 종류 개수가 된다.
    
    int minLen = 100000; // 구하는 구간
    unordered_map<string, int> count; // while문 반복 내에서 매 반복마다 해당 구간의 보석 종류 개수를 이 unordered_map 으로 셀 것이다. (Key 정렬 필요 없으므로 map 보단 더 빠른 unordered_map 채택)
    int i;
    int start = 0;
    int end = 0;
    while (true) {
        // end 포인터 업뎃 👉 보석의 모든 종류를 하나 이상씩 포함하는 곳까지
        for (i = end; i < gems.size(); ++i) {
            count[gems[i]]++;
            if (count.size() == kind.size()) {
                end = i;
                break;
            }
        }
        // end 포인터가 업뎃되지 못하고 빠져나와 gems 를 넘어섰다면 더 이상 업뎃할 구간 없으므로 종료
        if (i == gems.size())
            break;
        // start 포인터 업뎃 👉 보석의 모든 종류를 다 포함하되 이 보석을 제외하면 모든 종류를 포함할 수 없다싶은 곳 까지
        for (i = start; i < gems.size(); ++i) {
            if (count[gems[i]] == 1) {
                start = i;
                break;
            }
            else count[gems[i]]--;
        }
        // 현재 완성된 구간의 길이가 minLen 현재까지 구한 구간 최소 길이보다 작으면 minLen 업데이트
        if (end - start < minLen) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            minLen = end - start;
        }
        // 이제 새로운 구간을 다음 반복부터 잡아야한다.
        // start, end 모두 1 씩 증가시킴 (start 와 end 의 다음 "후보" 시작점)
        // gems[start] 는 제외해야하므로 count 에서 제거 
        count.erase(gems[start]);
        start++;
        end++;
    }
    
    return answer;
}