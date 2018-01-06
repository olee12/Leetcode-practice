#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    struct TrieNode
    {

        TrieNode *next[26];
        string word;
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
            word = "";
        }
    };

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words);
        vector<string> ret;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, ret);
                //return ret;
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &ret)
    {

        char ch = board[i][j];
        // cout<<i<<' '<<j<<' '<<ch<<endl;
        if (ch == '#' || p->next[ch - 'a'] == NULL)
            return;

        p = p->next[ch - 'a'];
        // cout<<"in dfs "<<ch<<" "<<p->word<<endl;

        if (p->word != "")
        {
            ret.push_back(p->word);
            p->word = "";
        }
        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, p, ret);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, ret);
        if (j > 0)
            dfs(board, i, j - 1, p, ret);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, ret);
        board[i][j] = ch;
    }

    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();

        for (string &word : words)
        {
            TrieNode *p = root;
            //  cout<<"[ root ]";
            for (char &ch : word)
            {
                if (p->next[ch - 'a'] == NULL)
                {
                    p->next[ch - 'a'] = new TrieNode();
                    //cout << "(new)";
                }
                // cout << " -> "<< ch;
                p = p->next[ch - 'a'];
            }
            p->word = word;
            // cout<<" : "<<p->word<<endl;
        }
        return root;
    }
};

int main()
{
}