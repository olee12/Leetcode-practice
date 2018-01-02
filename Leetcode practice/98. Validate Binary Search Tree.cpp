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
    bool isValidBST(TreeNode* root) {
        long long mx = numeric_limits<long long>::min();
        long long mn = numeric_limits<long long>::max();
        return sortBSTSol(root,mx,mn);
    }
    bool isValidBST(TreeNode* root,int &mxVal,int &mnVal){
        if(root==NULL) return true;

        bool ret = true;
        int aval,bval;
        aval = numeric_limits<int>::min();
        bval = numeric_limits<int>::max();

        mxVal = mnVal = root->val;
        if(root->left!=NULL){
        ret = ret & isValidBST(root->left,aval,bval);
        ret = ret & (root->val > aval);

        mxVal = max(mxVal,aval);
        mnVal = min(mnVal,bval);
        }
        if(root->right!=NULL){
        aval = numeric_limits<int>::min();
        bval = numeric_limits<int>::max();

        ret = ret & isValidBST(root->right,aval,bval);
        ret = ret & (root->val < bval);

        mxVal = max(mxVal,aval);
        mnVal = min(mnVal,bval);
        }
       // printf("%d %d %d %d\n",root->val,mxVal,mnVal,ret);
        return ret;
    }

    bool sortBSTSol(TreeNode *root,long long minVal,long long maxVal){
        if(root==NULL) return true; 
        if(root->val >= maxVal || root->val <= minVal ) return false;
        return sortBSTSol(root->left,minVal,root->val) && sortBSTSol(root->right,root->val,maxVal);
    }

};




int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(-1);

    Solution sol;
    printf("----%d----\n",sol.isValidBST(root));
}