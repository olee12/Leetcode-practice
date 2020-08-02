#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;



class Solution {
public:
    void deleteNode(ListNode* node) {
        // 1 2 3 4 5 6
        if(node == NULL) return;
        if(node->next == NULL) {
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->Add(2);
    head->Add(3);
    head->Add(4);
    head->Add(5);
    head->Add(6);
    head->Print();
    Solution sol;
    sol.deleteNode(head->Get(3));
    head->Print();
    return 0;
}
