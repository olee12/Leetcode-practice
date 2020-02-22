/*
 * =====================================================================================
 *
 *       Filename:  124. Binary Tree Maximum Path Sum.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/11/2019 16:51:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    typedef pair<int,int> pii;

    int maxPathSum(TreeNode* root) {
        pii ret = maxSum(root);
        // printf("ret.first %d, ret.second %d\n", ret.first, ret.second);
        return max(ret.first, ret.second);
    }
    pii maxSum(TreeNode *root) {
        if(root == NULL) {
            return make_pair(numeric_limits<int>::min(), numeric_limits<int>::min());
        }
        pii lft = maxSum(root->left);
        pii rght = maxSum(root->right);
        // printf("%d lft[%d %d] rght[%d %d]\n", root->val, lft.first, lft.second, rght.first, rght.second);
        pii cur = make_pair(numeric_limits<int>::min(), numeric_limits<int>::min());
        
        cur.first = max(max(lft.first, rght.first),0) + root->val;
        
        cur.second = max(lft.second, rght.second);
        cur.second = max(cur.second, root->val + max(lft.first,0) + max(rght.first,0));
        
        return cur;
    }
};

int main() {

    return 0;
}
