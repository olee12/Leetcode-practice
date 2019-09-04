#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;

const int maxn = 101;

set<int> people[maxn];
int par[maxn];
int dRank[maxn];
char inp[maxn];
void init(int p) {
    for(int i = 1;i<=p;i++){
        people[i].clear();
        dRank[i] = 0;
        par[i] = i;
    }
}

int find_par(int r) {
    return par[r] == r ? r : par[r] = find_par(par[r]);
}

int main()
{
    int test;
    int p,t;
    int u,v;
    scanf("%d", &test);
    while(test--) {
        scanf(" %d %d ",&p,&t);
        // printf("okay\n");
        init(p);
        while(fgets(inp,maxn,stdin)){
            // printf("inside %d %s",strlen(inp), inp);
            if(inp[0]=='\n') break;
            sscanf(inp, " %d %d ",&u,&v);
            people[u].insert(v);
        }
        int ret = p;
        for(int i = 1;i<=p;i++) {
            for(int j = i + 1;j<=p;j++){
                // printf("%d %d\n",i,j);
                if(people[i]!=people[j]) continue;
                // printf("%d %d\n",i,j);
                int x = find_par(i);
                int y = find_par(j);
                // printf("%d %d %d %d\n",i,j,x,y);
                if (x == y) continue;
                ret--;
                if(dRank[x]>dRank[y]) {
                    par[y] = x;
                }else if(dRank[x]<dRank[y]){
                    par[x] = y;
                }else {
                    par[x] = y;
                    dRank[y]++;
                }
                
            }
        }
        printf("%d\n",ret);
        if(test) printf("\n");
    }
    return 0;
}
