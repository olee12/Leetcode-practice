#include <iostream>
#include <vector>
#include <map>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    //olee12
    map<int,vector<TreeNode*> > dp;
    vector<TreeNode *> allPossibleFBT(int N)
    {
        dp.clear();
        vector<TreeNode *> ret = dfs(N);
        cout << "size: " << ret.size() << endl;
        return dfs(N);
    }
    vector<TreeNode *> dfs(int N)
    {
        vector<TreeNode *> ret;
        if (N == 0)
            return ret;
        if (N == 1)
        {
            ret.push_back(new TreeNode(0));
            return ret;
        }
        if(dp[N].size()) return dp[N];
        for (int i = 1; i < N; i += 2)
        {
            TreeNode *root = new TreeNode(0);

            vector<TreeNode *> left = dfs(i);
            vector<TreeNode *> right = dfs(N - i - 1);
            for (TreeNode *&lt : left)
            {
                for (TreeNode *&rt : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = lt;
                    root->right = rt;
                    ret.push_back(root);
                }
            }
        }
        return dp[N] = ret;
    }
};

int main()
{
    return 0;
}