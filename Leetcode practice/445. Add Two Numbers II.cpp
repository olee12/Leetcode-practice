#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        int n1 = 0, n2 = 0;

        while (c1 != NULL)
        {
            c1 = c1->next;
            n1++;
        }
        while (c2 != NULL)
        {
            c2 = c2->next;
            n2++;
        }
        c1 = l1;
        c2 = l2;

        
        int carry = 0;
        ListNode *ret = NULL;

        if (n1 == n2)
        {
            ret = addTwoList(l1, l2, carry);
        }
        else
        {
            int diff = abs(n1 - n2);
            if (n1 < n2)
            {
                swap(&c1, &c2);
            }
            ListNode *rem = c1;
            cout<<diff<<endl;
            for(;diff--;c1=c1->next);
            ret = addTwoList(c1,c2,carry);
            ListNode **head = &ret;
            addCarry(rem,c1,head,carry);
            ret = *head;
        }

        if (carry)
        {
            ret = pushFront(ret, carry);
        }
        return ret;
    }

    void swap(ListNode **a,ListNode **b){
        ListNode *tmp = *a;

        *a = *b;
        *b = tmp;
    }

    ListNode *pushFront(ListNode *rest, int val)
    {
        ListNode *ret = new ListNode(val % 10);
        ret->next = rest;
        return ret;
    }

    void addCarry(ListNode *l1,ListNode *c1,ListNode **ret,int &carry){
        if(l1==c1){
            return ;
        }

        addCarry(l1->next,c1,ret,carry);

        int sum = l1->val + carry;
        carry = sum/10;
        ListNode *rest = pushFront(*ret,sum);
        cout<<"-- "<<rest->val<<endl;
        *ret = rest;
        ret = &rest;
    }

    ListNode *addTwoList(ListNode *l1, ListNode *l2, int &carry)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        ListNode *rest = addTwoList(l1->next, l2->next, carry);
        int sum = (carry + l1->val + l2->val);
        carry = sum / 10;
        return pushFront(rest, sum);
    }
};
int main()
{
}