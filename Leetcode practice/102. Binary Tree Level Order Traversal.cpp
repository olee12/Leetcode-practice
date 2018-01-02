
#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(root==NULL) return ret;
        BFS(root,ret);
        return ret;
    }
    void BFS(TreeNode *root,vector<vector<int> > &ret)
    {
        deque<int> dq;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *tmp;
        int f = 0;
        while(q.empty()==false){
            dq.clear();
            int nodeCount = q.size();
            while(nodeCount>0){
                nodeCount--;
                tmp = q.front();
                q.pop();
                dq.push_back(tmp->val);
                if(tmp->left!=NULL) q.push(tmp->left);
                if(tmp->right!=NULL) q.push(tmp->right);
            }
            ret.push_back({dq.begin(),dq.end()});   
        }

    }
};



int main() {
    string line;
   printf("hello world\n");
}