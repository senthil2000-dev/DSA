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
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        int mindiff = INT_MAX;
        while(root) {
            if(root->data == K) return 0;
            mindiff = min(mindiff, abs(root->data - K));
            if(K<root->data)
                root = root->left;
            else
                root = root->right;
        }
        return mindiff;
    }
};