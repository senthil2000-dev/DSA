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
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {   vector<int> res;
        stack<Node*> s1, s2;
        while(!s1.empty() || !s2.empty() || root1 || root2) {
           while(root1) {
               s1.push(root1);
               root1 = root1->left;
           }
           
           while(root2) {
               s2.push(root2);
               root2 = root2->left;
           }
           
           if(s2.empty() || (!s1.empty() && s1.top()->data<=s2.top()->data)) {
               root1 = s1.top();
               res.push_back(root1->data);
               s1.pop();
               root1 = root1->right;
           }
           else {
               root2 = s2.top();
               res.push_back(root2->data);
               s2.pop();
               root2 = root2->right;
           }
       }
       return res;
    }
};