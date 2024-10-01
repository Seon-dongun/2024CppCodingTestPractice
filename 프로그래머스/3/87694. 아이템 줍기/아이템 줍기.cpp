#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
    int x,y,len;
};

int map[110][110] = {0,};
int visited[110][110] = {0,};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void FillRectangle(int x1,int y1,int x2,int y2)
{
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            if(i==x1 || i==x2 || j==y1 || j==y2)
            {
                if(map[i][j]==0)
                    map[i][j] = 1;
            }
            else
                map[i][j] = 2;
        }
    }
}

int bfs(int cx,int cy,int ix,int iy)
{
    queue<Data> q;
    q.push({cx,cy,0});
    visited[cx][cy] = 1;
    
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int len = q.front().len;
        q.pop();
        
        if(x==ix && y == iy)
            return len >> 1;
        
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx > 109 || ny > 109 || map[nx][ny] != 1 || visited[nx][ny] != 0)
                continue;
            
            visited[nx][ny] = 1;
            q.push({nx,ny,len+1});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for(int i=0;i<rectangle.size();i++)
    {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];
        
        FillRectangle(x1<<1,y1<<1,x2<<1,y2<<1);
    }
    
    answer = bfs(characterX<<1,characterY<<1,itemX<<1,itemY<<1);
    return answer;
}