#include <bits/stdc++.h>
using namespace std;
#include "TreeNode.h"


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return DFS(root,L,R);
    }

        
       
    TreeNode* DFS(TreeNode *root,int L,int R){
        if(root==NULL) return NULL;

        TreeNode *left = NULL;
        TreeNode *right = NULL;

        if(root->val >= L){
            left = DFS(root->left,L,R);
        }
        if(root->val <= R){
            right = DFS(root->right,L,R);
        }

        if(root->val >= L && root->val <= R){
            root->left = left,root->right = right;
            return root;
        }
        
        
        if(left != NULL) return left;
        return right;
    }
};


int main()
{

}