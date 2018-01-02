#include <bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return DFS(root->left,root->right);
    }


    bool DFS(TreeNode *left,TreeNode *right)
    {
        if(left == NULL || right==NULL) return left == right;

        if(left->val == right->val) return DFS(left->left,right->right) && DFS(left->right,right->left);
        return false;
    }

    bool BFS(TreeNode *left, TreeNode *right)
    {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(left);
        q2.push(right);

        while(q1.empty()==false && q2.empty()==false){
            TreeNode *a = q1.front();q1.pop();
            TreeNode *b = q2.front();q2.pop();
            if(a==NULL && b==NULL)  continue;
            if(a==NULL || b==NULL) return false;
            if(a->val != b->val) return false;
            q1.push(a->left);
            q1.push(a->right);
            q2.push(b->right);
            q2.push(b->left);
        }
        return true;
    }

};


int main()
{

}