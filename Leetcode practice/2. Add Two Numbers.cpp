/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode* rec(ListNode *pt1,ListNode *pt2,int carry)
 {
     if(pt1==NULL && pt2==NULL) {if(carry==0) return NULL;
         else {
             new ListNode(carry);
         }
     }

     int val1 = 0;
     int val2 = 0;
     if(pt1!=NULL) {
         val1 = pt1->val;
         pt1 = pt1->next;
     }
     if(pt2!=NULL) {
         val2 = pt2->val;
         pt2 = pt2->next;
     }
     int p = (val1 + val2 + carry)%10;
     carry = (val1 + val2 + carry)/10;
     ListNode *ptr = rec(pt1,pt2,carry);
     ListNode *my = new ListNode(p);
     my->next = ptr;
     return my;
 }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pt1 = l1;
        ListNode *pt2 = l2;

        return rec(pt1,pt2,0);

    }
};
