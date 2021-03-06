#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
       map<Node*, Node*> m;
       Node *cur = head;
       Node *nHead = new Node(-1);
       Node *ret = nHead;
       while(cur != NULL) {
           nHead->next = new Node(cur->val);
           nHead = nHead->next;
           m[cur] = nHead;
           cur = cur->next;
       }
       cur = head;
       nHead = ret->next;
       while(cur != NULL) {
           if (m.count(cur->random))
                nHead->random = m[cur->random];
            cur = cur->next;
            nHead = nHead->next;
       }
       return ret->next;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
