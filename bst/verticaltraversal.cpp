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
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front();
            Node* curr = p.first;
            int hd = p.second;
            q.pop();
            mp[hd].push_back(curr->data);
            if(curr->left) q.push({curr->left, hd-1});
            if(curr->right) q.push({curr->right, hd+1});
        }
        
        for(auto v: mp) {
            for(auto x: v.second) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};