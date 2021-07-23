#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* build(int pre[], int &preInd, int is, int ie, set<int> s) {
    if(is>ie) return NULL;
    Node* temp = new Node(pre[preInd++]);
    int i = distance(s.begin(), s.find((temp->data)));
    temp->left = build(pre, preInd, is, i-1, s);
    temp->right = build(pre, preInd, i+1, ie, s);
    return temp;
}

Node* constructTree(int pre[], int size)
{
    set<int> s(pre, pre+size);
    int preInd = 0;
    return build(pre, preInd, 0, size-1, s);
}