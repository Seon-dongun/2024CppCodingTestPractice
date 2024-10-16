#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Pos
{
    int z,x,y;
};

bool operator==(Pos& a,Pos& b)
{
    return (a.z==b.z && a.x==b.x && a.y==b.y);
}

int L,R,C;
char map[30][30][30];
int visited[30][30][30];

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
int dz[6] = {1,-1,0,0,0,0};

Pos start,e;

void Init()
{
    memset(visited,0,sizeof(visited));
    for(int k=0;k<L;k++)
    {
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cin >> map[k][i][j];
                if(map[k][i][j]=='S')
                    start = {k,i,j};
                if(map[k][i][j]=='E')
                    e = {k,i,j};
            }
        }      
    }
}

int BFS()
{
    queue<pair<Pos,int>> q;
    q.push({start,0});
    visited[start.z][start.x][start.y] = 1;
    
    while(!q.empty())
    {
        Pos cur = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(cur==e)
            return time;
        
        for(int i=0;i<6;i++)
        {
            Pos next = {cur.z + dz[i],cur.x+dx[i],cur.y+dy[i]};
            
            if(next.z < 0 || next.z >= L || next.x < 0 || next.x >= R || next.y < 0 || next.y >=C)
                continue;
            
            if(visited[next.z][next.x][next.y]==1 || map[next.z][next.x][next.y]=='#')
                continue;
            
            q.push({next,time+1});
            visited[next.z][next.x][next.y] = 1;
        }
    }
    
    return -1;
}

int main()
{
    while(1)
    {    
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0)
            break;
        
        Init();
        
        int result = BFS();
        if(result==-1)
            cout <<"Trapped!\n";
        else
            cout << "Escaped in " << result << " minute(s).\n";
    }
    
    return 0;
    
}