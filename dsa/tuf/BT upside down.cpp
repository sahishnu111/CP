//
// Created by OMEN on 14-03-2026.
//
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // Your code goes here

        // we will do level by level traversal
        if(!root) return nullptr;
        // base case
        TreeNode *l= nullptr;
        TreeNode *r= nullptr;

        while(root){
            TreeNode *temp=root->left;
            root->left=l;
            l=root->right;
            root->right=r;
            r=root;
            root=temp;


        }

        return r;

    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        Solution sol;
        // input and call sol.upsideDownBinaryTree
    }
    return 0;
}


