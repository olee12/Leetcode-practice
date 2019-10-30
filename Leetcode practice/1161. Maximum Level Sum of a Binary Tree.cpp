#include <bits/stdc++.h>
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
    int maxLevelSum(TreeNode* root) {
        map<int,int> dict;
        rec(root,1,&dict);
        int level = numeric_limits<int>::max();
        int ret = numeric_limits<int>::min();
        for(auto &it:dict) {
            // printf("%d %d\n",it.first,it.second);
            if (it.second > ret) {
                ret = it.second;
                level = it.first;
            }else if(it.second == ret) level = min(level, it.first);
        }
        return level;   
    }
    void rec(TreeNode *root,int level, map<int,int> *dict) {
        if(root == NULL) return ;
        dict->operator[](level) += root->val;
        rec(root->left, level + 1, dict);
        rec(root->right, level + 1, dict);
    }
};

int main() {
    return 0;
}