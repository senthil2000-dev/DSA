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

void uptoK(vector<int> &v, struct Node *root, int k) {
    if(root==NULL) return;
    if(k==0) v.push_back(root->data);
    uptoK(v, root->left, k-1);
    uptoK(v, root->right, k-1);
}

vector<int> Kdistance(struct Node *root, int k) {
    vector<int> v;
    uptoK(v, root, k);
    return v;
}

int main() {
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
	int k=2;
    vector<int> klevel = Kdistance(root,k);
    for(int x: klevel) {
        cout<<x<<' ';
    }
}
