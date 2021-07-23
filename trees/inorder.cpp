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

void inorder(TreeNode* root, vector<int> &in) {
    if(root == nullptr) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

vector<int> inorderTraversal(TreeNode* root) {
      vector<int> in;
      inorder(root, in);
      return in;
}

int main() {
	TreeNode *root=new TreeNode(1);
	root->right=new TreeNode(2);
	root->right->left=new TreeNode(3);
	vector<int> pre = inorderTraversal(root);
    for(int x: pre) {
        cout<<x<<' ';
    }
}
