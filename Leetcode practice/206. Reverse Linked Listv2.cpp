#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *next, *prv, *cur;
        next = cur = head;
        prv = NULL;
        while(next != NULL) {
            cur = next;
            next = cur->next;
            cur->next = prv;
            prv = cur;
        }
        return prv;
    }
};

ListNode* addToList(ListNode *root, int n) {
    ListNode *node = new ListNode(n);
    ListNode *cur = root;
    if (root == NULL) {
        return node;
    }
    while(cur->next != NULL) cur = cur->next; 
    cur->next = node;
    return root;
} 

void PrintList(ListNode *root) {
    printf("list ["); 
    while(root) {
        printf(" %d", root->val);
        root = root->next;
    }
    printf("]\n");
}


int main(int argc, char const *argv[])
{
    ListNode *root = addToList(NULL, 1);
    root = addToList(root, 2);
    // root = addToList(root, 3);
    PrintList(root);
    Solution sol;
    ListNode *rev = sol.reverseList(root);
    PrintList(rev);
    return 0;
}
