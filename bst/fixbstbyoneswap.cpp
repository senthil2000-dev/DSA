#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution {
public:
    Node *first = NULL, *second = NULL, *prev = NULL;
    void get2Nodes(Node* root) {
        if(!root) return;
        get2Nodes(root->left);
        if(prev && root->data < prev->data) {
            if(!first)
                first = prev;
            second = root;
        }
        prev = root;
        get2Nodes(root->right);
    }
    void correctBST( struct Node* root )
    {
        get2Nodes(root);
        swap(first->data, second->data);
    }
};