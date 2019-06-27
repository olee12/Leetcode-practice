#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
using namespace std;
class Trie
{
public:
    const int CASE = 'a';
    class CNode
    {
    public:
        CNode *next[26];
        string edge[26];
        bool isWord;
        CNode()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
                edge[i] = "";
            }
            isWord = false;
        }
    };
    /** Initialize your data structure here. */
    CNode *root;
    Trie()
    {
        this->root = new CNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        CNode *t = root;
        int i = 0, j = 0;
        while (word.size())
        {
            i = 0;
            j = 0;
            int indx = word[0] - CASE;
            string &edge = t->edge[indx];
            while (i < edge.size() && j < word.size() && edge[i] == word[j])
                i++, j++;

            if (i == 0 && j == 0) {
                CNode *newNode = new CNode(); // create new node
                t->edge[indx] = word;         // create edge
                t->next[indx] = newNode;      // point to the new node
                t = newNode;
                word = "";
            }
            else if (i < edge.size() && j <= word.size()) {
                // create new node
                CNode *nextNode = new CNode();
                // create the next edge, (facebook) (facepack) => (book)
                string nextedge = edge.substr(i);
                edge.resize(i);

                nextNode->edge[nextedge[0] - CASE] = nextedge;
                nextNode->next[nextedge[0] - CASE] = t->next[indx];
                t->next[indx] = nextNode;
                word = word.substr(j);
                t = nextNode;
            }
            else {
                t = t->next[indx];
                word = word.substr(j);
            }
            
        }
        t->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        CNode *t = root;
        int i, j, indx;
        while (word.size())
        {
            i = j = 0;
            indx = word[0] - CASE;
            string &edge = t->edge[indx];
            if(edge.size()==0) return false;
            while (i < edge.size() && j < word.size() && edge[i] == word[j])
                i++, j++;
            if (i == edge.size() && j <= word.size()) {
                t = t->next[indx];
                word = word.substr(j);
            }
            else {
                return false;
            }
        }
        return t->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        CNode *t = root;
        int i, j, indx;
        while (word.size()) {
            i = j = 0;
            indx = word[0] - CASE;
            string &edge = t->edge[indx];
            if(edge.size()==0) return false;
            while (i < edge.size() && j < word.size() && edge[i] == word[j])
                i++, j++;
            if (i < edge.size() && j == word.size())
                return true;
            else if (i == edge.size() && j <= word.size()) {
                t = t->next[indx];
                word = word.substr(j);
            }
            else {
                return false;
            }
        }
        return true;
    }
    void PrintTrie(CNode *t, int dept) {
        for (int i = 0; i < 26; i++) {
            if (t->next[i] == NULL)
                continue;
            for (int j = 0; j < dept * 4; j++)
                printf("-");
            printf("%s %d\n", t->edge[i].c_str(), t->isWord);
            this->PrintTrie(t->next[i], dept + 1);
        }
    }
};
/**
 *["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]] 
 * 
 */
int main()
{
    Trie *trie = new Trie();
    // trie->insert("for");
    // trie->insert("fora");

    // trie->PrintTrie(trie->root, 0);
    // trie->search("foa");
    // cout << trie->startsWith("a") << endl;
    cout << "for " << trie->search("a") << endl;
    // cout<<trie->search("thereinfo")<<endl;
    // cout<<trie->startsWith("thereinf")<<endl;
}
