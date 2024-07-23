#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tpc;
int parent[51];
vector<int> party[51];
vector<int> tp;

void init() {
    cin >> n >> m;
    cin >> tpc;

    int tmp;
    for (int i = 0; i < tpc; i++) {
        cin >> tmp;
        tp.push_back(tmp);
    }

    int pcnt, num;
    for (int i = 0; i < m; i++) {
        cin >> pcnt;
        for (int j = 0; j < pcnt; j++) {
            cin >> num;
            party[i].push_back(num);
        }
    }
}

int find(int a) {
    if (a == parent[a]) 
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

bool isUnion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    return false;
}

int main() {
    init();
    int answer = m;
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int n1 = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            int n2 = party[i][j];
            merge(n1, n2);
        }
    }
    
    for (int i = 0; i < m; i++) {
        bool goParty = true;
        for (int j = 0; j < party[i].size(); j++) {
            if (goParty == false)
                break;

            int n1 = party[i][j];
            for (int k = 0; k < tp.size(); k++) {
                int n2 = tp[k];
                if (isUnion(n1, n2) == true) {
                    goParty = false;
                    break;
                }
            }
        }

        if (goParty == false)
            answer--;
    }
    cout << answer << endl;
    return 0;
}
