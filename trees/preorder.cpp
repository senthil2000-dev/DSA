#include <bits/stdc++.h>
using namespace std;
vector<int> pre;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> preorderTraversal(TreeNode* root) {
    if(root == nullptr) return pre;
    pre.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return pre;
}

 int main() {
	TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->right->left=new TreeNode(40);
	root->right->right=new TreeNode(50);
	vector<int> pre = preorderTraversal(root);
    for(int x: pre) {
        cout<<x<<' ';
    }
}
