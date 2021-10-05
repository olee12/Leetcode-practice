#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        morrisTraversal(root);
    }

    void morrisTraversal(TreeNode *root)
    {
        printf("morris traversal\n");
        TreeNode *cur = root;

        TreeNode *pred = NULL, *x = NULL, *y = NULL;

        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                // printf("%d ", cur->val);

                if (pred != NULL && pred->val > cur->val)
                {
                    y = cur;
                    if (x == NULL)
                        x = pred;
                }

                pred = cur;

                cur = cur->right;
            }
            else
            {
                TreeNode *leftNode = cur->left;
                while (leftNode->right != NULL && leftNode->right != cur)
                {
                    leftNode = leftNode->right;
                }

                if (leftNode->right == NULL)
                {
                    leftNode->right = cur;
                    cur = cur->left;
                }
                else if (leftNode->right == cur)
                {
                    leftNode->right = NULL;
                    // current is the node
                    // printf("%d ", cur->val);
                    if (pred != NULL && pred->val > cur->val)
                    {
                        y = cur;
                        if (x == NULL)
                            x = pred;
                    }
                    pred = cur;
                    cur = cur->right;
                }
                else
                {

                    cur = cur->left;
                }
            }
        }
        // printf("x: %d, y: %d\n", x->val, y->val);
        if (x != NULL && y != NULL)
        {
            swap(x->val, y->val);
        }
    }

    void inorderStack(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *one = NULL, *two = NULL, *pred = NULL;
        while (!st.empty() || cur != NULL)
        {
            while (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *last = st.top();
            st.pop();

            if (pred != NULL && pred->val > last->val)
            {
                // printf("pred:  %d, last: %d\n", pred->val, last->val);
                two = last;
                if (one == NULL)
                    one = pred;
            }
            pred = last;
            // printf("%d ", last->val);
            if (last->right != NULL)
            {
                cur = last->right;
            }
        }
        // printf("x = %d y = %d\n", one->val, two->val);
        swap(one->val, two->val);
    }

    void fixByRecInorder(TreeNode *root)
    {
        lastValue = xvalue = yvalue = NULL;
        rec(root);
        if (xvalue != NULL && yvalue != NULL)
        {
            swap(xvalue->val, yvalue->val);
        }
    }
    TreeNode *lastValue;
    TreeNode *xvalue;
    TreeNode *yvalue;
    void rec(TreeNode *root)
    {
        if (root == NULL)
            return;
        rec(root->left);
        if (lastValue != NULL && lastValue->val > root->val)
        {
            yvalue = root;
            if (xvalue == NULL)
                xvalue = lastValue;
        }
        lastValue = root;
        rec(root->right);
    }

    void printInorder(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (!st.empty() || cur != NULL)
        {
            while (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode *last = st.top();
            st.pop();
            cout << last->val << ' ';
            if (last->right != NULL)
            {
                cur = last->right;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(4,
                                  new TreeNode(8,
                                               new TreeNode(2,
                                                            new TreeNode(1), new TreeNode(3)),
                                               new TreeNode(6, NULL, new TreeNode(7))),
                                  new TreeNode(12,
                                               new TreeNode(10, new TreeNode(9), new TreeNode(11)), new TreeNode(14)));
    // TreeNode *root = new TreeNode(14, new TreeNode(10), new TreeNode(12));
    Solution sol;
    // sol.recoverTree(root);
    sol.morrisTraversal(root);
    sol.printInorder(root);
    /* code */
    return 0;
}
