#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int burnTree(TreeNode* root, int leaf, int &dist, int &res) {
    if(!root) return 0;
    if(root->val == leaf) { dist = 0; return 1; }
    int ldist = -1, rdist = -1;
    int lh = burnTree(root->left, leaf, ldist, res);
    int rh = burnTree(root->right, leaf, rdist, res);
    if(ldist!=-1) {
        dist = ldist + 1;
        res = max(res, dist+rh);
    }
    if(rdist!=-1) {
        dist = rdist + 1;
        res = max(res, dist+lh);
    }
    return max(lh, rh) +1;
}

int solve(TreeNode* A, int B) {
    int res = 0;
    int distance = -1;
    burnTree(A, B, distance, res);
    return res;
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->left=new TreeNode(70);
    root->right->left->left=new TreeNode(80);
    cout<<solve(root, 80)<<endl; //only leaf node input allowed
}
