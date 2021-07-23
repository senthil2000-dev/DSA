#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> v;
    if(!root) return v;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> line;
    int count;
    while (!q.empty()) {
        count = q.size();
        for(int i=0; i<count; ++i) {
            TreeNode* curr = q.front(); q.pop();
            line.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        v.push_back(line);
        line.clear();
    }
    return v;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if(root==nullptr) return v;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    vector<int> line;
    while (q.size()!=1){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==nullptr) {
            v.push_back(line);
            line.clear();
            q.push(nullptr);
            continue;
        }
        line.push_back(curr->val);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    v.push_back(line);
    line.clear();
    return v;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    vector<vector<int>> levels = levelOrder2(root);
    for(auto x: levels) {
        for(auto i: x) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
