//
// Created by OMEN on 14-03-2026.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
#include <bits/stdc++.h>
using namespace std;

class BSTIterator {
public:
    // we will create min heap of all the nodes in the tree and maintain a pointer to current node
    priority_queue<int, vector<int>,greater<int>> pq;
    vector<int> nodes;
    int n=0;
    int curr=0;

    BSTIterator(TreeNode* root){
        // we will traverse the tree and add all the nodes to the min heap
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            pq.push(curr->data);
            n++;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

        }

        // convert this min heap to a vector and maintain a pointer to current node
        while(!pq.empty()){
            nodes.push_back(pq.top());
            pq.pop();
        }



    }

    bool hasNext() {
        return curr < n;
    }

    int next() {
        return nodes[curr];
    }

    bool hasPrev() {
        return curr > 0;
    }

    int prev() {
        return nodes[curr-1];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        // input and call BSTIterator
    }
    return 0;
}