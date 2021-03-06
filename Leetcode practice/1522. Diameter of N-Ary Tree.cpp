#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int diameter(Node* root) {
        return dfs(root).first;
    }

    pair<int,int> dfs(Node* root) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int,int> ret = {0,0};
        int max_first_value = 0;
        int mx1 = 0, mx2 = 0;

        for (int i = 0;i<root->children.size();i++) {
            // cout << root->val << "--"<< root->children[i]->val<<endl;
            pair<int,int> child = dfs(root->children[i]);
            if (mx1 < child.second) {
                mx2 = mx1;
                mx1 = child.second;
            }else if (mx2 < child.second) {
                mx2 = child.second;
            }
            max_first_value = max(max_first_value, child.first);
        }
        ret.second = max(mx1, mx2) + 1;
        if (ret.second == 1) {
            ret.first = 0;
        }else {
            ret.first = max(max_first_value, mx1 + mx2);
        }
        // cout << root->val<< "::"<< ret.first<<","<<ret.second<<", mx1::"<<mx1<<", mx2: "<<mx2<<" , mx_chield: "<<max_first_value<<"\n";
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


/*

35--52
35--95
95--38
38--70
38--72
95--22
22--54
54--42
42--73
42--63
22--2
2--98


52::0,1, mx1::0, mx2: 0 , mx_chield: 0
70::0,1, mx1::0, mx2: 0 , mx_chield: 0
72::0,1, mx1::0, mx2: 0 , mx_chield: 0
38::2,2, mx1::1, mx2: 1 , mx_chield: 0
73::0,1, mx1::0, mx2: 0 , mx_chield: 0
63::0,1, mx1::0, mx2: 0 , mx_chield: 0
42::2,2, mx1::1, mx2: 1 , mx_chield: 0
54::2,3, mx1::2, mx2: 0 , mx_chield: 2
98::0,1, mx1::0, mx2: 0 , mx_chield: 0
2::1,2, mx1::1, mx2: 0 , mx_chield: 0
22::5,4, mx1::3, mx2: 2 , mx_chield: 2
95::5,5, mx1::4, mx2: 0 , mx_chield: 5
35::5,6, mx1::5, mx2: 0 , mx_chield: 5



*/