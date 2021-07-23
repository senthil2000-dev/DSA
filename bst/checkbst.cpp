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

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    int prev = INT_MIN;
    bool isBST(Node* root) 
    {
        if(!root) return true;
        if(!isBST(root->left)) return false;
        if(root->data<=prev) return false;
        prev = root->data;
        return isBST(root->right);
    }
};