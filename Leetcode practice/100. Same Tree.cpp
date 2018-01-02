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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL || q==NULL) return q==p;
        return BFS(p,q);

    }

    bool BFS(TreeNode *root1,TreeNode *root2)
    {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(root1);
        q2.push(root2);

        while(q1.empty()==false && q2.empty()==false){
            TreeNode *a = q1.front();q1.pop();
            TreeNode *b = q2.front();q2.pop();

            if(a==NULL && b==NULL) continue;
            if(a==NULL || b==NULL) return false;

            if(a->val != b.val) return false;
            q1.push(a->left);
            q1.push(a->right);
            q2.push(b->left);
            q2.push(b->right);
        }
        return true;
    }


};



int main()
{

}