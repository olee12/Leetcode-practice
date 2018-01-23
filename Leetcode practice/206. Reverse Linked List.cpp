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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       // return iter(head,NULL);
        return iter(head);
    }
    ListNode* iter(ListNode* head){
        ListNode *prv = NULL;
        while(head != NULL){
            ListNode *next = head->next;
            head->next = prv;
            prv = head;
            head = next;
        }
        return prv;
    }
    ListNode* rec(ListNode *head,ListNode *prev){
        if(head==NULL) return prev;
        ListNode *rest = head->next;
        head->next = prev;
        return rec(rest,head);
    }
};


int main(){
    return 0;
}