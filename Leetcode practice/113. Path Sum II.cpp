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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > ret;
        vector<int> path;

        dfs(root,sum,0,path,ret);
        return ret;

    }

    void dfs(TreeNode *root,int &sum,int curr,vector<int> &path,vector< vector<int> > &ret){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            if(curr + path.back() == sum) ret.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        dfs(root->left,sum,curr + path.back(),path,ret);
        dfs(root->right,sum,curr + path.back(),path,ret);
        path.pop_back();
    }
};



int main()
{

}