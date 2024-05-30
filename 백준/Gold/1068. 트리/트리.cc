#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];
int answer = 0;
void search(int id,int del) {
    if (tree[id].size() == 0 || (tree[id].size() == 1 && tree[id][0]==del))
        answer++;

    for (int i = 0; i < tree[id].size(); i++) {
        if(tree[id][i]!=del)
            search(tree[id][i],del);
    }
}

int main() {
    int n, num, del, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == -1)
            root = i;
        else
            tree[num].push_back(i);
    }
    cin >> del;

    if (del== root)
        cout << 0;
    else {
        search(root,del);
        cout << answer;
    }
    return 0;
}