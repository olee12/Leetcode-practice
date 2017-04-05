#include <bits/stdc++.h>
using namespace std;



///Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class compare {
public :
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*,vector<ListNode*>, compare > q;

        for(auto it = lists.begin();it != lists.end();it++){
            if( *(it) != NULL ) q.push(*it);
        }

        ListNode *head;
        ListNode *dummy = new ListNode(0);
        head = dummy;
       // cout << "Q size : "<<q.size()<<endl;
        while(q.size()){
             ListNode* mtop = q.top();
            dummy->next = mtop;
            dummy = dummy->next;
            q.pop();
            if(mtop->next!=NULL)
                q.push(mtop->next);

        }
        dummy = NULL;
        return head = head->next;

    }
};



int main() {

}
