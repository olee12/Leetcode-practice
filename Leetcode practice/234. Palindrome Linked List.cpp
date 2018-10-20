#include <iostream>
#include "ListNode.h"
using namespace std;


class Solution {
public:
    //olee12
    bool isPalindrome(ListNode* head) {
        ListNode *root = head;
        ListNode **forward = &head;
        return dfs(root,forward);
    }
    bool dfs(ListNode *root,ListNode **forward){
        if(root == NULL) return true;
        bool ret = dfs(root->next,forward);
        ListNode *head = *forward;
        ret = ret && head->val == root->val;
        *forward = head->next;
        return ret;
    }
};

int main()
{
    ListNode *tmp = new ListNode(1);
    ListNode *head = tmp;
    tmp->next = new ListNode(0);
    tmp = tmp->next;
    tmp->next = new ListNode(1);
    tmp = tmp->next;
    tmp->next = NULL;
    Solution sol;
    printf("%d\n",sol.isPalindrome(head));
    return 0;
}