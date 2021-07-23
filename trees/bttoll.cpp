#include<bits/stdc++.h>
using namespace std;
vector<int> pre;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void preorderTraversal(TreeNode* root) {
    if(root == nullptr) return;
    cout<<root->val<<' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void buildlist(TreeNode *root, TreeNode* &next) {
    if(!root) return;
    buildlist(root->right, next);
    buildlist(root->left, next);
    if(next) {root->right=next; root->left=nullptr; }
    next=root;
}

void flatten(TreeNode* root) {
    TreeNode* next = NULL;
    return buildlist(root, next);
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->left=new TreeNode(70);
    flatten(root);
    preorderTraversal(root);
}
