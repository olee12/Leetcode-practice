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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        
        ListNode *head = NULL,*ptr = NULL;
        ListNode* tmp = new ListNode(0);
        while(l1!=NULL && l2!=NULL){
            if(l2->val > l1->val){
                tmp = new ListNode(l1->val);
                l1 = l1->next;
            }else {
                tmp = new ListNode(l2->val);
                l2 = l2->next;
            }
            if(head == NULL){
                head = tmp;
                ptr = tmp;
            }else{
                ptr->next = tmp;
                ptr = tmp;
            }
        }
        
        if(l1==NULL) ptr->next = l2;
        else if(l2==NULL) ptr->next = l1;
        return head;
    }
};