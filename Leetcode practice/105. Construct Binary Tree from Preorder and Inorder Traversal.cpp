
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ptr = 0;
        return buildTree(preorder,inorder,0,inorder.size()-1,ptr);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int start,int end,int &ptr){
        
        if(start>end) return NULL;
        
        int inIdx = find(inorder.begin(),inorder.end(),preorder[ptr]) - inorder.begin();
        TreeNode *root = new TreeNode(preorder[ptr++]);
        root->left = buildTree(preorder,inorder,start,inIdx-1,ptr);
        root->right = buildTree(preorder,inorder,inIdx+1,end,ptr);
        return root;
    }
};




int main() {
    string line;
   printf("hello world\n");
}