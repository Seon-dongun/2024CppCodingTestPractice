#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node{
    int id,x,y;
    Node* left;
    Node* right;
}Node;

bool cmp(Node& a, Node& b){
    if(a.y > b.y){
        return true;
    }
    else if(a.y < b.y)
        return false;
    else{
        return a.x<b.x;
    }
}

void makeTree(Node* root, Node* child){
    if(root->x >child->x){
        if(root->left==NULL){
            root->left = child;
            return;
        }
        makeTree(root->left,child);
    }
    else{
        if(root->right==NULL){
            root->right = child;
            return;
        }
        makeTree(root->right,child);
    }
}

vector<int> tmp,tmp2;
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    tmp.push_back(root->id);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    tmp2.push_back(root->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> tree;
    for(int i=0;i<nodeinfo.size();i++)
        tree.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1],NULL,NULL});
    
    sort(tree.begin(),tree.end(),cmp);
    
    Node* root = &tree[0];
    for(int i=1;i<tree.size();i++)
        makeTree(root,&tree[i]);
    
    preorder(root);
    postorder(root);
    answer.push_back(tmp);
    answer.push_back(tmp2);
    return answer;
}