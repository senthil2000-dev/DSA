#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
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

TreeNode* ctree(vector<int>& preorder, vector<int>& inorder, int &pre, int ins, int ine) {
    if(ins>ine) return nullptr;
    int val = preorder[pre++];
    TreeNode* node = new TreeNode(val);
    int i;
    for(i=ins; i<=ine; i++) {
        if(inorder[i] == val) break;
    }
    node->left = ctree(preorder, inorder, pre, ins, i-1);
    node->right = ctree(preorder, inorder, pre, i+1, ine);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    int pre = 0;
    return ctree(preorder, inorder, pre, 0, n-1);
}

int main() {
    vector<int> preorder{3,9,20,15,7}, inorder{9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    vector<vector<int>> levels = levelOrder2(root);
    for(auto x: levels) {
        for(auto i: x) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
