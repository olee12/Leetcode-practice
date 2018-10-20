#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    //olee12
    vector<vector<int>> levelOrder(TreeNode* root) {
        return BFS(root);
    }

    vector<vector<int> > BFS(TreeNode *root){
        if(root ==NULL) return vector<vector<int> >();
        vector<vector<int> > ret;
        queue<TreeNode *> q;
        deque<int> tmp;
        
        ret.push_back({root->val});
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);

        while(q.size()){
            int qSize = q.size();
            tmp.clear();
            while(qSize--){
                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ret.push_back({tmp.begin(),tmp.end()});
        }

        return ret;
    }
};

int main()
{
    
}