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

void postorder(TreeNode* root, vector<int> &post) {
    if(root == nullptr) return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
      vector<int> post;
      postorder(root, post);
      return post;
}

int main() {
	TreeNode *root=new TreeNode(1);
	root->right=new TreeNode(2);
	root->right->left=new TreeNode(3);
	vector<int> pre = postorderTraversal(root);
    for(int x: pre) {
        cout<<x<<' ';
    }
}
