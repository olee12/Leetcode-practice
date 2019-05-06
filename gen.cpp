#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("./inp.txt","w",stdout);
    srand(time(0));
    printf("200000 2000\n");
    set<int> st;
    while(st.size()<200000){
        st.insert((rand()%200000)+1);
    }
    vector<int> vals;
    for(auto it : st){
        vals.push_back(it);
    }
    random_shuffle(vals.begin(),vals.end());
    for(auto it : vals){
        printf("%d ",it);
    }
    printf("\n");
}