#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;
struct pos {
    int x, y;
};

int N, K, L;
int snakeDir;
int map[101][101] = { 0, };
int apples[101][101] = { 0, };
queue<pair<int, char>> orders;
deque<pos> snake;
bool isGameOver = false;

void MoveSnake()
{
    pos nextPos;
    if (snakeDir == 1)
        nextPos = { snake.front().x-1,snake.front().y };
    else if (snakeDir == 2)
        nextPos = { snake.front().x+1,snake.front().y };
    else if (snakeDir == 3)
        nextPos = { snake.front().x,snake.front().y-1 };
    else if (snakeDir == 4)
        nextPos = { snake.front().x,snake.front().y+1 };

    if (nextPos.y < 1 || nextPos.x < 1 || nextPos.y > N || nextPos.x > N || map[nextPos.x][nextPos.y] == 1)
    {
        isGameOver = true;
        return;
    }

    snake.push_front(nextPos);
    map[nextPos.x][nextPos.y] = 1;
    if (apples[nextPos.x][nextPos.y] == 1)
        apples[nextPos.x][nextPos.y] = 0;
    else
    {
        map[snake.back().x][snake.back().y] = 0;
        snake.pop_back();
    }
}

// 상하좌우 1234
void ChangeDir(char changeDir)
{
    if (snakeDir == 1)
    {
        if (changeDir == 'L')
            snakeDir = 3;
        else
            snakeDir = 4;
    }
    else  if (snakeDir == 2)
    {
        if (changeDir == 'L')
            snakeDir = 4;
        else
            snakeDir = 3;
    }
    else if (snakeDir == 3)
    {
        if (changeDir == 'L')
            snakeDir = 2;
        else
            snakeDir = 1;
    }
    else if (snakeDir == 4)
    {
        if (changeDir == 'L')   
            snakeDir = 1;
        else  
            snakeDir = 2;
    }
}

void Init()
{
    cin >> N;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        apples[x][y] = 1;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int sec;
        char dir;
        cin >> sec >> dir;
        orders.push({ sec,dir });
    }

    // 상하좌우 1234
    snakeDir = 4;
    snake.push_back({ 1,1 });
    map[1][1] = 1;
}

int main()
{
    Init();

    int time = 0;
    while (1)
    {
        if (isGameOver)
            break;

        if (!orders.empty() &&time == orders.front().first)
        {
            char changeDir = orders.front().second;
            orders.pop();

            ChangeDir(changeDir);
        }

        MoveSnake();
        time++;
    }

    cout << time;
    return 0;
}