#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    void invert(TreeNode *root) {
        if(root == NULL) return;

        if(root->left != NULL) invert(root->left);
        if(root->right != NULL) invert(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return ;
    }
};


int main() {

    return 0;
}
