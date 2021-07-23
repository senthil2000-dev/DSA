#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int count = q.size();
        int first, last;
        for(int i=0; i<count; i++) {
            pair<TreeNode*, long long> p = q.front();
            TreeNode *curr = p.first;
            int c = p.second;
            q.pop();
            if(i==0) first=c;
            if(i==count-1) last=c;
            if(curr->left) q.push({curr->left, 2*c+1});
            if(curr->right) q.push({curr->right, 2*c+2});
        }
        res = max(res, last-first+1);
    }
    return res;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    cout<<widthOfBinaryTree(root);
}
