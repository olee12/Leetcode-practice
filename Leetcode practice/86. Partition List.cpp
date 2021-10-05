#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lowHead = new ListNode(-1);
        ListNode *highHead = new ListNode(-1);
        ListNode *c1 = lowHead;
        ListNode *c2 = highHead;
        while (head != NULL)
        {
            if (head->val < x)
            {
                c1->next = head;
                c1 = c1->next;
            }
            else
            {
                c2->next = head;
                c2 = c2->next;
            }
            head = head->next;
        }

        if (lowHead->next == NULL)
        {
            return highHead->next;
        }
        else if (highHead->next == NULL)
        {
            return lowHead->next;
        }
        c1->next = highHead->next;
        c2->next = NULL;
        // printf("%d--%d\n", c1->val, highHead->next->val);
        // lowHead->Print();
        return lowHead->next;
    }
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lowHead = new ListNode(-1);
        ListNode *highHead = new ListNode(-1);
        ListNode *c1 = lowHead;
        ListNode *c2 = highHead;
        while (head != NULL)
        {
            if (head->val < x)
            {
                c1->next = head;
                c1 = c1->next;
            }
            else
            {
                c2->next = head;
                c2 = c2->next;
            }
            head = head->next;
        }

        if (lowHead->next == NULL)
        {
            return highHead->next;
        }
        else if (highHead->next == NULL)
        {
            return lowHead->next;
        }
        c1->next = highHead->next;
        c2->next = NULL;
        // printf("%d--%d\n", c1->val, highHead->next->val);
        // lowHead->Print();
        return lowHead->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->Add(4);
    head->Add(3);
    head->Add(2);
    head->Add(5);
    head->Add(2);

    Solution sol;
    ListNode *nhead = sol.partition(head, 3);
    nhead->Print();
    /* code */
    return 0;
}
