#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
 
using namespace std;
 
const int maxn = 1000005;
const int maxm = 505;
char str[maxn];
char pattern[maxm];
int result[maxm];
 
const int mxtree = 505*505;
int tree_size = 0;
struct Node {
    int nxt[26];
    int suffixLink;
    int outputLink;
    vector<int> idx;
    bool leaf;
    Node() {
        // memset(nxt, -1, sizeof(nxt));
        // suffixLink = 0;
        // outputLink = 0;
        // idx = 0;
        // leaf = 0;
    }
    int& operator[](const int &i)  {
        return nxt[i];
    }
};
 
Node tree[mxtree];
 
 
void insert(char *pattern, int idx) {
    int root = 0;
    for (int i = 0; pattern[i]; i++){
        int ch = pattern[i] - 'a';
        if(tree[root][ch]==-1) {
            if(tree_size > mxtree) tree_size = 0;
            tree[root][ch] = ++tree_size;
 
            Node &n = tree[tree[root][ch]];
            memset(n.nxt, -1, sizeof(n.nxt));
            n.suffixLink = 0;
            n.outputLink = 0;
            n.idx.clear();
            n.leaf = 0;
        }
        root = tree[root][ch];
    }
    tree[root].idx.push_back(idx);
    tree[root].leaf = true;
}
 
void buildAutoMata() {
    queue<int> q;
    for(int i = 0;i<26;i++) {
        if(tree[0][i]!= -1)
            q.push(tree[0][i]);
    }
 
    while(q.size()) {
        int u = q.front();
        q.pop();
 
        for(int i = 0;i<26;i++) {
            if(tree[u][i]==-1)
                continue;
            int v = tree[u][i];
            int sufixLinkNode = tree[u].suffixLink;
            while(sufixLinkNode && tree[sufixLinkNode][i] == -1) {
                sufixLinkNode = tree[sufixLinkNode].suffixLink;
            }
            tree[v].suffixLink = tree[sufixLinkNode][i] == -1 ? 0 : tree[sufixLinkNode][i];
            tree[v].outputLink = tree[tree[v].suffixLink].leaf ? tree[v].suffixLink : tree[tree[v].suffixLink].outputLink;
            q.push(v);
        }
    }
}
 
 
void match(char *str) {
    memset(result, 0, sizeof(result));
    int root = 0;
    int len = strlen(str);
    for(int i = 0;i < len;i++) {
        int to = str[i] - 'a';
 
        while(root != 0 && tree[root][to] ==-1){
            root = tree[root].suffixLink;
        }
        
        root = tree[root][to] == -1?0:tree[root][to];
        
        // printf("ch %c, root %d\n", str[i], root);
        int tmp = root;
        while(tmp != 0) {
                for( int j = 0; j < tree[tmp].idx.size();j++){
                    // printf("j -- %d  tmp -- %d  \n", j , tmp);
                    // printf("sz %d  \n", tree[tmp].idx.size() );
                    // printf("[tmp][j] %d  \n", tree[tmp].idx[j] );

                    result[tree[tmp].idx[j]]++;

                }
            tmp = tree[tmp].outputLink;
        }
    }
}
 
 
void printTree(int root, int depth, char ch) {
 
 
    for(int i = 0;i < 2*depth;i++) printf(" ");
    printf("%d %c sl[%d] ol[%d] idx[%d] leaf[%d] ", root, ch, tree[root].suffixLink, tree[root].outputLink, tree[root].idx.size(), tree[root].leaf);
    int flag = 0;
    for(int i = 0;i<26;i++){
        if(tree[root][i]==-1) continue;
        printTree(tree[root][i], depth+1, i+ 'a');
        flag = 1;
    }
    if (flag==0) printf("|\n");
   
 
 
}
 
 
 
 
 
int main() {
    // cout<<tree.size()<<endl;
    freopen("./loj/inp/inp01.txt", "r", stdin);
    int test, cas = 1;
    int n;
    scanf("%d", &test);
    while(test--) {
        memset(tree[0].nxt, -1, sizeof(tree[0].nxt));
        tree[0].idx.clear();
        scanf("%d", &n);
        scanf("%s", str);
        // printf("%s\n", str);
        for(int i = 0; i < n; i++) {
            scanf("%s", pattern);
            insert(pattern, i + 1);
        }
        buildAutoMata();
        // printTree(0, 0, 'x');
        match(str);
        printf("Case %d:\n", cas++);
        for(int i = 1;i<=n;i++) printf("%d\n", result[i]);
        
        tree_size = 0;
        memset(tree[0].nxt, -1, sizeof(tree[0].nxt));
 
    }
    return 0;
}