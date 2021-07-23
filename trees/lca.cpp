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

//important function
bool findPath(TreeNode* root, vector<TreeNode*> &v, int n) {
    if(!root) return false;
    v.push_back(root);
    if(root->val == n) return true;
    if(findPath(root->left, v, n) || findPath(root->right, v, n)) return true;
    v.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int n1 = p->val;
    int n2 = q->val;
    vector<TreeNode*> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2)) {
        return NULL;
    }
    int i;
    for(i=1; i<path1.size() && i<path2.size(); i++) {
        if(path1[i] != path2[i]) return path1[i-1];
    }
    return path1[i-1] == path2[i-1] ? path1[i-1] : NULL;
}

//assuming both keys present as in leetcode constraints
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    int n1 = p->val;
    int n2 = q->val;
    if(!root) return root;
    if(root->val == n1 || root->val == n2) return root;
    TreeNode* lca1 = lowestCommonAncestor2(root->left, p, q); 
    TreeNode* lca2 = lowestCommonAncestor2(root->right, p, q);
    if(lca1 && lca2) return root;
    if(lca1) return lca1;
    return lca2;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
    root->right->left=new TreeNode(60);
	root->right->right=new TreeNode(70);
    root->right->right->right=new TreeNode(80);
    cout<<lowestCommonAncestor(root, root->right->left, root->right->right->right)->val<<endl; //expected output 30
    cout<<lowestCommonAncestor2(root, root->right->left, root->right->right->right)->val<<endl; //expected output 30
}
