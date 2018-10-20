#include <iostream>
#include <ListNode.h>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Compare {
    public:
    bool operator() (ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode* >,Compare> q;
        for(auto it : lists){
            if(it != NULL)
                q.push(it);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        while(q.size()){
            ListNode *tmp = q.top();
            dummy->next = tmp;
            dummy = dummy-> next;
            q.pop();
            if(tmp->next != NULL)
                q.push(tmp->next);
        }
        dummy->next = NULL;
        return head = head->next;
    }
};





int main()
{

}