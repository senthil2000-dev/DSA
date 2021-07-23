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

void left(Node *root, int level, int &maxlevel, vector<int> &v) {
    if(!root) return;
    if(level>maxlevel) {
        v.push_back(root->data);
        maxlevel++;
    }
    left(root->left, level+1, maxlevel, v);
    left(root->right, level+1, maxlevel, v);
}

vector<int> leftView(Node *root) {
    int maxlevel = 0;
    vector<int> v;
    left(root, 1, maxlevel, v);
    return v;
}

vector<int> leftView2(Node *root) {
    vector<int> v;
    if(!root) return v;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        for(int i=0; i<count; i++) {
            Node *curr = q.front();
            q.pop();
            if(i==0)
                v.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
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
    vector<int> lv = leftView2(root);
    for(int x: lv) cout<<x<<' ';
}
