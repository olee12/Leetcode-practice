#include <bits/stdc++.h>
using namespace std;
#include "ListNode.h"

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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast == NULL || fast->next == NULL) return false;

        return true;

        // slow = head;
        // while(slow != fast){
        //     slow = slow->next;
        //     fast = fast->next;
        // }
         
    }
};


int main()
{
    
}