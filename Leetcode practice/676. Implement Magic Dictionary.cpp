#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    bool end;
    int val;
    Node* child[26];
    Node(int ch) {
        this->val = ch;
        for(int i = 0;i<26;i++) this->child[i] = NULL;
        this->end = false;
    }
};

class TrieTree {
    public:
    Node *root;
    TrieTree() {
        root = new Node('.');
    }
    void insert(string &word) {
        Node *p = root;
        for(char &ch : word) {
            int t = ch - 'a';
            if (p->child[t] == NULL) {
                p->child[t] = new Node(t);
            }
            p = p->child[t];
        }
        p->end = true;
    }
    bool search(string &word) {
        return rec(root, 0, word, false);
    }
    bool rec(Node *root, int pos, string &word, bool changed) {
        if(root==NULL) return false;
        if (pos == word.size()) {
            if(changed && root->end) return true; 
            else return false;
        }
        int t = word[pos] - 'a';
        Node *nxt = root->child[t];
        bool ret = false; 
        if(nxt != NULL)  
            if(rec(nxt, pos +1 , word, changed)) 
                return true;

        if(changed == false) {
            for (int i = 0; i < 26; i++) {
                if (i != t && rec(root->child[i], pos + 1, word, !changed))
                    return true;
            }
        }
        return false;
    }
};

class MagicDictionary {
public:
    TrieTree *tree;
    /** Initialize your data structure here. */
    MagicDictionary() {
        tree = new TrieTree();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string &str : dict) tree->insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
       return tree->search(word); 
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

int main() {
    vector<string> dict = {"hello","hhllo", "leetcode"};
    MagicDictionary *obj = new MagicDictionary();
    obj->buildDict(dict);
    // obj->search("hello");
    assert(obj->search("hello")==true);
    assert(obj->search("hhllo")==true);
    assert(obj->search("hell") == false);
    assert(obj->search("leetcoded")==false);
}