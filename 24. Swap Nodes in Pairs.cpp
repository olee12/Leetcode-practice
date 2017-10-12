#include <cstdio>
#include <cstdlib>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **current = &head;
        while(*current && (*current)->next){
            ListNode *a = *current;
            ListNode *b = a->next;
            
            a->next = b->next;
            b->next = a;
            *current = b;
            current = &(a->next);            
        }
        return head;
    }
};

int main()
{
    //printf("");
}
