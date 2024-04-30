#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int dp[100][100];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            dp[i][j] = 0;
    }
    
    for(int i=0;i<results.size();i++)
        dp[results[i][0]-1][results[i][1]-1] = 1;
    

     for (int k = 0; k < n; k++){ 
        for (int i = 0; i < n; i++){ 
            for (int j = 0; j < n; j++){
                if(dp[i][k] == true && dp[k][j] == true)
                    dp[i][j] = true;
            }
        }
    }
    
    // 기준값이 행 일때의 true의 개수 + 기준값이 열 일때의 true의 개수 = n-1 이면 순위 확정 가능!
    for (int i = 0; i < n; ++i){
        int temp = 0;
        for (int j = 0; j < n; ++j){ // 어짜피 i와 j와 같은 경우는 무조건 false이므로 중복 계산해도 temp값에 영향이 없다
            if (dp[i][j] == true)
                temp++;
            if (dp[j][i] == true)
                temp++;
        }
        
        if (temp == n-1)
            answer++;
    }
      
    return answer;
}