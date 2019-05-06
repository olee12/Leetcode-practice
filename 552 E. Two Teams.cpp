#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 50;

typedef pair<int,int> pii;

int arr[maxn];
pii tree[maxn * 4];
int lazy[maxn * 4];
int result[maxn];

void build(int node, int beg, int end) {
    if(beg == end) {
        tree[node] = make_pair(arr[beg],beg);
        return ;
    }
    int mid = (beg + end) / 2;
    int left = node * 2;
    int right = left + 1;
    build(left, beg, mid);
    build(right, mid + 1, end);
    if(tree[left].first >= tree[right].first) tree[node] = tree[left];
    else tree[node] = tree[right];
}

void pushDown(int node, int beg, int end) {
    tree[node] = make_pair(lazy[node],beg);
    if(beg != end) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = -1;
    return ;
}

void update(int node, int beg, int end, int &i, int &j, int &val) {

    if(lazy[node] != -1){
        pushDown(node,beg,end);
    }

    if(end < i || beg > j) return ;

    if(beg >=i && end <= j) {
        lazy[node] = val;
        pushDown(node,beg,end);
        return;
    }
    int mid = (beg + end) / 2;
    int left = node * 2;
    int right = left + 1;
    update(left, beg, mid, i, j, val);
    update(right, mid + 1, end, i, j, val);
    if(tree[left].first >= tree[right].first) tree[node] = tree[left];
    else tree[node] = tree[right];   
}

void fillValue(int beg,int end, int val) {
    for(int i = beg;i<=end;i++){
        if(result[i]==0) result[i] = val;
    }
}

int main() {
    freopen("inp.txt","r",stdin);
    int n,k;
    while(scanf("%d %d",&n,&k)==2){
        for(int i = 1;i<=n;i++) scanf("%d",arr + i);
        memset(lazy,-1,sizeof(lazy));
        build(1,1,n);
        int team = 0;
        int val = 0;
        while(tree[1].first > 0){
            
            pii node = tree[1];
            int left = max(node.second - k,1);
            int right = min(n,node.second + k);
            printf("-> %d %d. %d %d\n",tree[1].first,tree[1].second,left,right);
            update(1,1,n,left,right,val);
            fillValue(left,right, team+1);
            team^=1;
        }

        for(int i = 1;i<=n;i++){
            printf("%d",result[i]);
        }
        printf("\n");

    }
}