#include<bits/stdc++.h>
#include "TreeNode.h"
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return dfs(root).first;
    }

    pair<int,int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0,0};
        }
        pair<int,int> l = dfs(root->left);
        pair<int,int> r = dfs(root->right);
        pair<int,int> ret = {0,0};
        ret.second = max(l.second, r.second) + 1;
        if (ret.second == 1) // leaf node 
            ret.first = 0;
        else 
            ret.first = max(l.first, max(r.first, l.second + r.second));
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



