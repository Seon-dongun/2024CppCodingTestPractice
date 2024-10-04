#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct pos
{
    int x, y;
};

bool cmp(pos a, pos b)
{
    if (a.x < b.x)
        return true;
    else if (a.x > b.x)
        return false;
    else
    {
        if (a.y < b.y)
            return true;
        else
            return false;
    }
}


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, x, y;
    vector<pos> lines;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        lines.push_back({ x,y });
    }

    sort(lines.begin(), lines.end(), cmp);

    int s = lines[0].x;
    int e = lines[0].y;
    int answer = 0;
    for (int i = 1; i < lines.size(); i++)
    {
        if (lines[i].x > e)
        {
            answer += e - s;
            s = lines[i].x;
            e = lines[i].y;
        }
        else if (lines[i].x <= e)
        {
            if(e <lines[i].y)
                e = lines[i].y;
        }
    }
    answer += e - s;

    cout << answer;
}