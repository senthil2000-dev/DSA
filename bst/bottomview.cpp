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
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front();
            Node* curr = p.first;
            int hd = p.second;
            q.pop();
            mp[hd] = curr->data;
            if(curr->left) q.push({curr->left, hd-1});
            if(curr->right) q.push({curr->right, hd+1});
        }
        
        for(auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};