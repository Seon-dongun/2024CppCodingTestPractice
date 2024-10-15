#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
struct Pos
{
    int x, y;
};

Pos operator+(Pos& a, Pos& b)
{
    int nx = a.x + b.x;
    int ny = a.y + b.y;

    Pos newPos = { nx,ny };

    return newPos;
}

int C;
int W, H;
char map[1000][1000];
int fireMap[1000][1000];
int visited[1000][1000] = { 0, };
Pos start;
vector<Pos> firePos;

Pos dxy[4] = { {0,1},{0,-1},{-1,0},{1,0} };

void MakeMap()
{
    firePos.clear();

    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '*')
                firePos.push_back({ i,j });
            else if (map[i][j] == '@')
                start = { i,j };
        }
    }
}

void MakeFireMap()
{
    memset(visited, 0, sizeof(visited));
    memset(fireMap, 0, sizeof(fireMap));

    queue<Pos> q;
    for (int i = 0; i < firePos.size(); i++)
    {
        q.push(firePos[i]);
        fireMap[firePos[i].x][firePos[i].y] = 1;
        visited[firePos[i].x][firePos[i].y] = 1;
    }

    while (!q.empty())
    {
        Pos curPos = q.front();
        q.pop();


        for (int i = 0; i < 4; i++)
        {
            Pos newPos = curPos + dxy[i];
            if (newPos.x < 0 || newPos.y < 0 || newPos.x >= H || newPos.y >= W)
                continue;

            if (visited[newPos.x][newPos.y] == 1 || map[newPos.x][newPos.y] == '#')
                continue;

            visited[newPos.x][newPos.y] = 1;
            fireMap[newPos.x][newPos.y] = fireMap[curPos.x][curPos.y] + 1;
            q.push(newPos);
        }
    }
}

int BFS()
{
    memset(visited, 0, sizeof(visited));

    queue<pair<Pos, int>> q;
    q.push({ start,1 });
    visited[start.x][start.y] = 1;

    while (!q.empty())
    {
        Pos curPos = q.front().first;
        int t = q.front().second;
        q.pop();

        if (curPos.x == 0 || curPos.y == 0 || curPos.x == H - 1 || curPos.y == W - 1)
            return t;

        for (int i = 0; i < 4; i++)
        {
            Pos newPos = curPos + dxy[i];

            if (visited[newPos.x][newPos.y] == 1 || map[newPos.x][newPos.y] != '.')
                continue;

            if (fireMap[newPos.x][newPos.y] == 0 || fireMap[newPos.x][newPos.y] > t + 1)
            {
                visited[newPos.x][newPos.y] = 1;
                q.push({ newPos,t + 1 });
            }
        }
    }

    return -1;
}

int main()
{
    cin >> C;
    while (C--)
    {
        MakeMap();
        MakeFireMap();

        int time = BFS();
        if (time == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << time << endl;;
    }
}