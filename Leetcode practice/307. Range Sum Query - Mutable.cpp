#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int beg, end;
    int val;
    Node *left, *right;
    Node(int b, int e) : beg(b), end(e),val(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    Node *root;
    SegmentTree(int b, int e) {
        root = new Node(b, e);
    }
    void build(vector<int> &inp) {
        build(root, inp);
    }
    void build(Node *r, vector<int> &inp) {
        if(r->end < r->beg) return ;
        if(r->beg == r->end) {
            r->val = inp[r->beg];
            return;
        }
        int mid = (r->beg + r->end) / 2;
        if(r->left == NULL) r->left = new Node(r->beg, mid);
        if(r->right == NULL) r->right = new Node(mid+1, r->end);
        build(r->left, inp);
        build(r->right, inp);
        r->val = r->left->val + r->right->val;
        return;
    }
    void update(int b, int e, int val) {
        update(root, new Node(b,e), val);
    }
    void update(Node *r, Node *e, int val) {
        if(r->end < r->beg) return ;
        if(r->beg > e->end || r->end < e->beg) {
            return ;
        }
        if(r->beg >= e->beg && r->end <= e->end) {
            r->val = val;
            return;
        }
        int mid = ( r->beg + r->end) / 2;
        // if(r->left == NULL) r->left = new Node(r->beg, mid);
        // if(r->right == NULL) r->right = new Node(mid+1, r->end);
        update(r->left, e, val);
        update(r->right, e, val);
        r->val = r->left->val + r->right->val;
        return;
    }
    int query(int b, int e) {
        return query(root, new Node(b,e));
    }
    int query(Node *r, Node *e) {

        if(r == NULL) return 0;
        if(r->end < r->beg) return 0;
        if(r->beg > e->end || r->end < e->beg) {
            return 0;
        }
        if(r->beg >= e->beg && r->end <= e->end) {
            return r->val;
        }
        int mid = (r->beg + r->end) / 2;
        // if(r->left == NULL) r->left = new Node(r->beg, mid);
        // if(r->right == NULL) r->right = new Node(mid+1, r->end);
        return query(r->left, e) + query(r->right, e);

    }
};


class NumArray {
public:
    SegmentTree *tree;

    NumArray(vector<int>& nums) {
       tree = new SegmentTree(0, nums.size() - 1);
       tree->build(nums);
    }
    
    void update(int i, int val) {
        tree->update(i, i, val);  
    }
    
    int sumRange(int i, int j) {
       return tree->query(i, j); 
    }
};



int main(int argc, char const *argv[])
{
    vector<int> inp = {1,3,5};
    NumArray *nums = new NumArray(inp);
    assert(nums->sumRange(0,2)==9);
    nums->update(1, 2);
    assert(nums->sumRange(0,2)==8);
    assert(nums->sumRange(1,1)==2);
    assert(nums->sumRange(1,2)==7);
    assert(nums->sumRange(0,1)==3);


    return 0;
}
