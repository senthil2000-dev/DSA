#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int k){
      data=k;
      left=right=NULL;
    }
};

int findMax(Node *root) {
    if(root == NULL) return INT_MIN;
    return max(root->data, max(findMax(root->right), findMax(root->left)));
}

int findMin(Node *root) {
    if(root == NULL) return INT_MAX;
    return min(root->data, min(findMin(root->right), findMin(root->left)));
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
}
