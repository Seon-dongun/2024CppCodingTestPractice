#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[50];
int parent[50];
int answer = 0;
void search(int id) {
    if (tree[id].size() == 0) {
        answer++;
        return;
    }

    for (int i = 0; i < tree[id].size(); i++) {
        search(tree[id][i]);
    }
}

void Delete(int del) {
    int p = parent[del];
    for (int i = 0; i < tree[p].size(); i++) {
        tree[p].erase(remove(tree[p].begin(),tree[p].end(),del),tree[p].end());
    }
    tree[del].clear();
}

int main() {
    int n, num, del, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        parent[i] = num;
        if (num == -1) {
            root = i;
            continue;
        }
        tree[num].push_back(i);
    }
    cin >> del;

    if (parent[del] == -1)
        cout << 0;
    else {
        Delete(del);
        search(root);
        cout << answer;
    }
    return 0;
}