#include <iostream>
#include <vector>

using namespace std;
const int maxn = 30000 + 5;
const int maxm = 500000 + 5;

struct vertex {
    int par;
    int rnk;
    int sum;
};

vertex subSet[maxn];


int find_par(int r) {
    return r==subSet[r].par ? r : subSet[r].par = find_par(subSet[r].par);
}

int doUnion(int u,int v) {
    int x = find_par(u);
    int y = find_par(v);
    
    if (x == y) return subSet[x].sum;

    if(subSet[x].rnk > subSet[y].rnk) {
        subSet[y].par = x;
        return subSet[x].sum += subSet[y].sum;
    }else if( subSet[x].rnk < subSet[y].rnk) {
        subSet[x].par = y;
        return subSet[y].sum += subSet[x].sum;
    }else {
        subSet[x].par = y;
        subSet[y].rnk++;
        return subSet[y].sum += subSet[x].sum;
    }

}

void clear(int n) {
    for(int i = 0;i<=n;i++) {
        subSet[i].par = i;
        subSet[i].rnk = 0;
        subSet[i].sum = 1;
    }
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n,m;
        scanf("%d %d",&n,&m);
        clear(n);
        int maximum = 1;
        for(int i = 0;i<m;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            maximum = max(maximum,doUnion(u,v));
        }
        // for(int i = 1;i<=n;i++){
        //     maximum = max(maximum, subSet[subSet[i].par].sum);
        // }
        printf("%d\n",maximum);
    }
    return 0;
}