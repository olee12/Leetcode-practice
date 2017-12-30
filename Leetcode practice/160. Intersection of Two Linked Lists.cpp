#include <bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0,len2 = 0;
        ListNode *n1=NULL,*n2=NULL;
        ListNode *h1 = headA;
        ListNode *h2 = headB;

        while(h1!=NULL){
            len1++;
            n1 = h1;
            h1 = h1->next;
        }
        while(h2!=NULL){
            len2++;
            n2 = h2;
            h2 = h2->next;
        }
        if((n1 != n2) || len1 == 0 || len2==0 ) return NULL;
        n1 = headA;
        n2 = headB;
        int dif = abs(len1-len2);
        if(len1>len2){
            while(dif--){
                n1 = n1->next;
            }
        }else if(len2>len1){
            while(dif--){
                n2 = n2->next;
            }
        }
        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};

int main()
{

}