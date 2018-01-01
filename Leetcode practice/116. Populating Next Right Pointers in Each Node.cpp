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
        connectRightDFS(root->left,root->right);
    }

    void connectRight(TreeLinkNode *root){
        TreeLinkNode *par = root,*cur;
        while(par->left!=NULL){
            cur = par;
            while(cur != NULL){
                cur->left->next = cur->right;
                if(cur->next != NULL){
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            par = par->left;
        }
    }
    void connectRightDFS(TreeLinkNode *node1, TreeLinkNode *node2){
        if(node1 == NULL || node2==NULL) return;
        node1->next = node2;
        if(node1->left != NULL){
            connectRightDFS(node1->right,node2->left);
            connectRightDFS(node1->left,node1->right);
            connectRightDFS(node2->left,node2->right);
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