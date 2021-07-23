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

int countNodes(TreeNode* root) {
    if(root==nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);    
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    cout<<countNodes(root)<<endl;
}
