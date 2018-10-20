#include <iostream>
#include <vector>
#include <unordered_map>

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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,bool> dict;
        for(int a:G) dict[a] = true;

        ListNode *cur = head;
        int ret = 1;
        while(cur != NULL && cur->next != NULL ){
            if(dict[cur->val] && !dict[cur->next->val]) ret++;
            cur = cur->next;
        }
        return ret;

    }
};



int main()
{
    return 0;
}