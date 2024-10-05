#include <iostream>

using namespace std;
int ledder[31][11] = {0,};
int n,m,h,maxledder;
bool findAnswer = false;
bool Move()
{
    for(int i=1;i<=n;i++)
    {
        int x = i;
        for(int j=1;j<=h;j++)
        {
            int y = j;
            
            if(ledder[y][x])
                x++;
            else if(x > 1 && ledder[y][x-1])
                x--;
        }
        
        if(x!=i)
            return false;
    }
    
    return true;
}

void dfs(int y,int cnt)
{
    if(maxledder == cnt)
    {
        if(Move())
        {
            findAnswer = true;
        }
        return;
    }
    
    // 가로선 추가하는 코드
    for (int i = y; i <= h;i++){
        for (int j = 1; j < n; j++){
            if(!ledder[i][j-1] && !ledder[i][j] && !ledder[i][j+1]){
                //사다리가 추가 될 수 있는 위치인지 확인
                ledder[i][j] = true; // 사다리 추가
                dfs(i, cnt + 1); // y좌표와 사다리 추가 개수 카운트
                ledder[i][j] = false; // 추가한 사다리 삭제
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> h;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        ledder[x][y] = 1;
    }
    
    
    for(int i=0;i<=3;i++)
    {
        maxledder = i;
        dfs(1,0);
        if(findAnswer)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}