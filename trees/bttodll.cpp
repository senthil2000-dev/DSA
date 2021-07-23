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

Node* recur(Node* root, Node* &prev) {
    if(!root) return NULL;
    Node* head = recur(root->left, prev);
    if(!prev) head = root;
    else {
        prev->right = root;
        root->left = prev; 
    }
    prev = root;
    recur(root->right, prev);
    return head;
}

Node* bToDLL(Node *root) {
    Node* prev = NULL;
    return recur(root, prev);
}


int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    Node *head = bToDLL(root);
    Node *curr = head;
    while(curr!=NULL) {
        cout<<curr->data<<' ';
        curr = curr->right;
    }
    cout<<endl;
}
