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

int check(TreeNode *root) {
    if(!root) return 0;
    int lh = check(root->left);
    if(lh==-1) return -1; 
    int rh = check(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return check(root) >= 0 ? true : false;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	// root->right->right->right=new TreeNode(80);
    cout<<isBalanced(root)<<endl;
}
