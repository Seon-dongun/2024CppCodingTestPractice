#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> book_time)
{
    int answer = 0, room[2410]={0,};
    int n = book_time.size();
    for(int i=0;i<n;i++)
    {
        int s = stoi(book_time[i][0].substr(0,2))*100 + stoi(book_time[i][0].substr(3)); // 시간 계산
        int e = stoi(book_time[i][1].substr(0,2))*100 + stoi(book_time[i][1].substr(3)) + 10; // 분 계산
        
        // 끝나는 시간의 경우 청소시간이 더해져서 고려되어야 하기 때문에, 끝나는 시간이 50분부터는 10분이 더해지면 시간이 한 시간 늘어나야함. 예를 들어 12:50의 표현인 1250 경우 10을 더하면 1260이 된다. 이 상황에서 100진법으로 구해보면 60이 나온다. 여기에 40을 더해주면 1300이 되어 우리가 원하는 13:00시 표현이 가능해진다.
        if(e % 100 >= 60) 
            e += 40;
        
        for(int j=s;j<e;j++) 
            room[j]++;
    }
    
    for(int i=0;i<2400;i++) 
        answer = max(answer, room[i]);
    return answer;
}