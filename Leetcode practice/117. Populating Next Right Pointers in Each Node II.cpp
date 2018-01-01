#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if(root == NULL) return ;
        connectRight(root);
    }

    void connectRight(TreeLinkNode *root){
        TreeLinkNode *start = new TreeLinkNode(0);
        TreeLinkNode *prv;
        TreeLinkNode *curr = root;

        while(curr!=NULL){
            prv = start;
            
            while(curr != NULL){
                if(curr->left != NULL){
                    prv->next = curr->left;
                    prv = prv->next;
                }
                if(curr->right != NULL){
                    prv->next = curr->right;
                    prv = prv->next;
                }
                curr = curr->next;
            }
            curr = start->next;
            start->next = NULL;
        }
    }

};

int main()
{
    TreeLinkNode *root = new TreeLinkNode(0);
    root->left = new TreeLinkNode(1);
    root->right = new TreeLinkNode(2);
    Solution sol;
    sol.connect(root);
    printf("%d\n",root->left->next->val);
}