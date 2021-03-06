#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        rec(root);
        return;
    }

    TreeNode* rec(TreeNode* root) {
        if(root==NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode *leftTail = NULL;
        TreeNode *rightTail = NULL;
        if(root->left != NULL) leftTail = rec(root->left);
        if(root->right != NULL) rightTail = rec(root->right);
        if(leftTail != NULL) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if(rightTail != NULL) return rightTail;
        return leftTail;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
