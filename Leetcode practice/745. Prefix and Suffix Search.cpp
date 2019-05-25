#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class TrieNode {
    public:
    TrieNode *next[27];
    int w;
    TrieNode() {
        w = 1<<30;
        for(int i = 0;i<27;i++) next[i] = NULL;
    }
    TrieNode*& operator[] (int i)  {
        return next[i];
    }
};

class WordFilter {
public:
    TrieNode *root;
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0;i<words.size();i++){
            string word = words[i]+'{';
            for(int st = 0;st<=words[i].size();st++){
                TrieNode *tree = root;
                for(int j = st; j < word.size()*2 - 1; j++ ) {
                    int ch = word[j%word.size()] - 'a';
                    // printf("%c",ch+97);
                    if((*tree)[ch] == NULL) {
                        (*tree)[ch] = new TrieNode();
                    }
                    
                        // if(tree->next[ch]!=NULL){
                        //     printf("[%x]",tree->next[ch]);
                        // }
                    

                    tree = (*tree)[ch];
                    tree->w = i;
                }
                // printf("\n");
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + '{' + prefix;
        TrieNode *tree = root;
        for(int i = 0;i<word.size();i++){
            int ch = word[i] - 'a';
            // printf("%c~",ch+97);
            // if(tree->next[ch]!=NULL){
            //                 printf("[%x]",tree->next[ch]);
            //             }
            if((*tree)[ch]==NULL) return -1;
            tree = (*tree)[ch];
        }
        return tree->w;
    } 
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


int main() {
    vector<string> words = {"apple"};
    WordFilter *wf = new WordFilter(words);
    printf("ret=%d\n",wf->f("a","e"));
}


// {"abbbababbb",
// "baaabbabbb",
// "abababbaaa",
// "abbbbbbbba",
// "bbbaabbbaa",
// "ababbaabaa",
// "baaaaabbbb",
// "babbabbabb",
// "ababaababb",
// "bbabbababa"}
// ,["","abaa"],["babbab",""],["ab","baaa"],["baaabba","b"],["abab","abbaabaa"],["","aa"],["","bba"],["","baaaaabbbb"],["ba","aabbbb"],["baaa","aabbabbb"]]