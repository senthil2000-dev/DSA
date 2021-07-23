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

int heightndia(TreeNode* root, int &diameter) {
    if(!root) return 0;
    int lh = heightndia(root->left, diameter);
    int rh = heightndia(root->right, diameter);
    diameter = max(diameter, 1+lh+rh); //lh+rh is path length as per leetcode
    return 1+max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    heightndia(root, diameter);
    return diameter;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
	root->right->right->right=new TreeNode(80);
    cout<<diameterOfBinaryTree(root)<<endl;
}
