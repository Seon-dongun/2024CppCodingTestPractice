#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<string, int> m;
        int n;
        cin >> n;
        getchar();
        for (int i = 0; i < n; i++)
        {
            string str, tmp,buf;
            getline(cin, str);

            istringstream ss(str);
            ss >> tmp;
            ss >> tmp;

            m[tmp]++;
        }

        int ans = 1;
        for (auto tmp : m)
            ans *= (tmp.second + 1);
        ans -= 1;
        cout << ans << endl;
    }
    return 0;
}