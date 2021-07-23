#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

bool isCSum(Node *root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    int sum = 0;
    if(root->left) sum+=root->left->key;
    if(root->right) sum+=root->right->key;
    return (root->key == sum && isCSum(root->left) && isCSum(root->right));
}

int main() {
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(12);
	root->right->left=new Node(3);
	root->right->right=new Node(9);
	cout<<isCSum(root)<<endl;
}
