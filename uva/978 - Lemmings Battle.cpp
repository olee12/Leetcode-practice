#include "bits/stdc++.h"
using namespace std;




vector<string> play(int num_groud,priority_queue<int> green, priority_queue<int> blue) {
    vector<string> ret;
    while(green.size()!=0 && blue.size()!=0) {
        vector<int> gv;
        vector<int> bv;
        while(gv.size() < num_groud && green.size()) {
            gv.push_back(green.top());
            green.pop();
        }
        while(bv.size() < num_groud and blue.size()) {
            bv.push_back(blue.top());
            blue.pop();
        }
        for(int i = 0; i<min(gv.size(), bv.size()); i++) {
            int mn = min(gv[i], bv[i]);
            gv[i]-=mn;
            bv[i]-=mn;
        }
        for(int &v: gv) {
            if(v > 0) green.push(v);
        }
        for(int &v: bv) {
            if(v>0) blue.push(v);
        }
    }
    if(green.size()==0 && blue.size()==0) {
        ret.push_back("green and blue died");
    }
    else if(green.size()) {
        ret.push_back("green wins");
        char buff[15];
        while(green.size()) {
            sprintf(buff, "%d", green.top());
            ret.push_back(buff);
            green.pop();
        }
    }else {
        ret.push_back("blue wins");
        char buff[15];
        while(blue.size()) {
            sprintf(buff, "%d", blue.top());
            ret.push_back(buff);
            blue.pop();
        }
    }
    return ret;
}


int main() {
    // freopen("./uva/inp/inp.txt", "r", stdin);
    int test;
    scanf("%d", &test);

    while(test--) {
        int s, sg, sb;
        scanf("%d %d %d", &s, &sg, &sb);
        priority_queue<int> green;
        priority_queue<int> blue;
        for(int i = 0;i<sg;i++) {
            int v;
            scanf("%d", &v);
            green.push(v);
        }
        for(int i = 0;i<sb;i++) {
            int v;
            scanf("%d", &v);
            blue.push(v);
        }
        vector<string> result = play(s, green, blue);
        for(string &str : result) {
            printf("%s\n", str.c_str());
        }
        if(test) {
            printf("\n");
        }
    }
    return 0;
}