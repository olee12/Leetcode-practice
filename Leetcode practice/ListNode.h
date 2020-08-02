
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode* Get(int n) {
        ListNode *root = this;
        while(root != NULL) {
            if(root->val == n) {
                return root;
            }
            root = root->next;
        }
    }
    ListNode* Add(int n)
    {
        ListNode *node = new ListNode(n);
        ListNode *cur = this;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
        return this;
    }
    void Print()
    {
        ListNode *root = this;
        printf("list [");
        while (root)
        {
            printf(" %d", root->val);
            root = root->next;
        }
        printf(" ]\n");
    }
};
