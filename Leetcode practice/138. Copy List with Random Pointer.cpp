#include <bits/stdc++.h>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
  public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        map<RandomListNode *, RandomListNode *> dict;
        if(head==NULL) return NULL;
        RandomListNode *ptr = head;

        while(ptr!=NULL){
            RandomListNode *copy = new RandomListNode(ptr->label);
            dict[ptr] = copy;
            ptr = ptr->next;
        }

        ptr = head;
        RandomListNode *tmp = new RandomListNode(0);
        RandomListNode *start = tmp;

        while(ptr!=NULL) {
            dict[ptr]->next = ptr->next;
            if(ptr->random != NULL)
                dict[ptr]->random = dict[ptr->random];
            tmp->next = dict[ptr];
            tmp = tmp->next;
            ptr = ptr->next;
        }
        return start->next;
    }
};


int main()
{

}