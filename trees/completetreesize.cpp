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

int countNodes2(TreeNode* root) {
    if(root==nullptr) return 0;
    TreeNode *curr = root, *curr2 = root;
    int h = 0;
    while (curr!=nullptr && curr2!=nullptr) {
        curr = curr->left;
        curr2 = curr2->right;
        h++;
    }
    if(!curr && !curr2) return pow(2, h) -1;
    return 1 + countNodes2(root->left) + countNodes2(root->right);
}

int countNodes(TreeNode* root) {
    if(root==nullptr) return 0;
    int lh=0, rh=0;
    TreeNode* curr = root;
    while (curr!=nullptr) {
        curr = curr->left;
        lh++;
    }
    curr = root;
    while (curr!=nullptr) {
        curr = curr->right;
        rh++;
    }
    if(lh==rh) return pow(2, lh) -1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->left=new TreeNode(70);
    cout<<countNodes2(root)<<endl;
}
