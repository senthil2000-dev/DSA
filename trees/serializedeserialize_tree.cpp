#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> v;
    if(!root) return v;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> line;
    int count;
    while (!q.empty()) {
        count = q.size();
        for(int i=0; i<count; ++i) {
            TreeNode* curr = q.front(); q.pop();
            line.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        v.push_back(line);
        line.clear();
    }
    return v;
}

void ser(TreeNode* root, string &s) {
    if(!root) { s+="n,"; return; }
    s += to_string(root->val) + ',';
    ser(root->left, s);
    ser(root->right, s);
}

TreeNode* des(string data, int &ptr) {
    string num = "";
    do {
        num += data[ptr]; 
        ptr++;
    } while(data[ptr]!=',');
    ptr++;
    if(num=="n") return NULL;
    int n = stoi(num);
    TreeNode* root = new TreeNode(n);
    root->left = des(data, ptr);
    root->right = des(data, ptr);
    return root;
}

string serialize(TreeNode* root) {
    string s="";
    ser(root, s);
    return s;
}

TreeNode* deserialize(string data) {
    int ptr = 0;
    return des(data, ptr);
}

int main() {
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(20);
	root->right=new TreeNode(30);
	root->left->left=new TreeNode(40);
	root->left->right=new TreeNode(50);
	root->right->right=new TreeNode(70);
    string s = serialize(root);
    cout<<s<<endl;
    TreeNode* head = deserialize(s);
    vector<vector<int>> levels = levelOrder2(head);
    for(auto x: levels) {
        for(auto i: x) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
