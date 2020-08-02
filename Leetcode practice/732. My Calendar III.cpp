#include <bits/stdc++.h>
using namespace std;

class Segment {
    public:
    int beg, end;
    int booked;
    int total;
    Segment *left, *right;
    Segment(int b, int e): beg(b), end(e), booked(0), total(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    Segment *root;
    SegmentTree(int b, int e) {
        root = new Segment(b, e);
    }
    int add(int b, int e, int val) {
        // printf("start: %d, end: %d\n",b, e);
        update(root, new Segment(b,e), val);
        // printf("--------------\n\n");
        return root->total;
    }
    void update(Segment *root, Segment *e, int val) {
        // printf("curr--> %d -- %d\n", root->beg, root->end);
        if(root==NULL) return; 
        if(root->end <= e->beg || e->end <= root->beg) {
            return ;
        }
        // inside
        if(root->beg >= e->beg && root->end <= e->end) {
        // printf("%d %d %d %d \n", root->beg, root->end, e->beg, e->end);
            root->booked += val;
            root->total += val;
            return ;
        }

        // intersect 
        int mid = (root->beg + root->end) / 2;
        if(root->left == NULL) root->left = new Segment(root->beg, mid);
        if(root->right == NULL) root->right = new Segment(mid, root->end);
        update(root->left, e, val);
        update(root->right, e, val);
        root->total = max(root->left->total,root->right->total) + root->booked;
    }
};

class MyCalendarThree {
public:
    SegmentTree *tree;
    
    MyCalendarThree() {
        tree = new SegmentTree(1, 10);
    }
    
    int book(int start, int end) {
        return tree->add(start, end, 1);
    }
};


int main()
{
    MyCalendarThree *cal = new MyCalendarThree();
    assert(cal->book(2,8) == 1); // returns 1
    assert(cal->book(3,6) == 2); // returns 1
    assert(cal->book(2, 7) == 3); // returns 2
    assert(cal->book(5,9) == 4);  // returns 3
}