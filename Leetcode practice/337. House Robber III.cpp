#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    map<TreeNode*,map<bool,int>> dp;
    int rob(TreeNode* root) {
        dp.clear();
        return rec(root,false);
    }
    int rec(TreeNode *root,int prev) {
        if(root == NULL) return 0;
        int ret = 0;
        if(dp[root].find(prev)!=dp[root].end()) {
            return dp[root][prev];
        }
        if(prev == false) {
            ret = max(ret,rec(root->left,true) + rec(root->right,true) + root->val);
        }
        ret = max(ret,rec(root->left,false) + rec(root->right,false));
        dp[root][prev] = ret;
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout<<"result: "<< sol.rob(root)<<endl;
}