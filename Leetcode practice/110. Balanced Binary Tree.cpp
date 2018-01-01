#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    bool isBalanced(TreeNode* root) {
        int hight = 0;
        return isBalancedDFS(root,hight);
    }

    
    bool isBalancedDFS(TreeNode *root,int &hight) {
        if(root==NULL) return true;
        int h1 = 0;
        int h2 = 0;
        bool ret1 = isBalancedDFS(root->left,h1);
        bool ret2 = isBalancedDFS(root->right,h2);
        hight = max(h1,h2) + 1;
        if((ret1 & ret2)==0) return false;
        if(abs(h1-h2)>1) return false;
        return true;
    }
};



int main()
{

}