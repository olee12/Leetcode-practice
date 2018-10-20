
#include <iostream>
#include <vector>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;


//Definition for a binary tree node.
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };



class Solution {
public:
//olee12
    TreeNode* buildTree(vector<int>& inorder,vector<int> postorder) {
        int ptr = postorder.size() - 1;
        unordered_map<int,int> inord;
        for(int i = 0;i<inorder.size();i++) {
            inord[inorder[i]] = i;
        }
        return buildTree(inord,postorder,0,inorder.size()-1,ptr);
    }
    TreeNode* buildTree(unordered_map<int,int>& inorder,vector<int>& postorder,int start,int end,int &ptr){
        if(start > end) return NULL;
        
        TreeNode *root = new TreeNode(postorder[ptr--]);
        int mid = inorder[root->val];
        root->right = buildTree(inorder,postorder,mid + 1, end, ptr);
        root->left = buildTree(inorder,postorder,start,mid -1,ptr);
        return root;
    }
};




int main() {
    string line;
   printf("hello world\n");
}