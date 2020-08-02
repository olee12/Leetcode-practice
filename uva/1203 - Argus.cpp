#include <bits/stdc++.h>
using namespace std;

struct Instruction {
    int id;
    int next_time;
    int diff;
    Instruction(int _id, int _next, int _interval) :id(_id), next_time(_next), diff(_interval) {} 
};

struct compareInstruction {
    bool operator () (Instruction &a, Instruction &b) {
        if (a.next_time == b.next_time) {
            return a.id > b.id;
        }
        return a.next_time > b.next_time;
    }
};


vector<int> process(vector<pair<int, int> > inp, int k) {
    if(inp.size()==0) return {};
    vector<int> ret;
    priority_queue<Instruction, vector<Instruction>, compareInstruction > q; 
    for(pair<int,int> &pii: inp) {
        q.push(Instruction(pii.first, pii.second, pii.second));
    }

    while(k > 0 && q.size()) {
        auto inst = q.top();
        ret.push_back(inst.id);
        q.pop();
        inst.next_time += inst.diff; 
        q.push(inst);
        k--;
    }
    return ret; 
}

int main() {
    // freopen("inp/inp.txt", "r", stdin);
    char buff[1000];
    vector<pair<int,int> > inp;
    while(scanf("%s", buff)) {
        if(buff[0]=='#') break;
        int id, diff;
        scanf("%d %d", &id, &diff);
        inp.push_back({id, diff}); 
        // printf("%s %d %d\n", buff, id, diff);
    }
    int k;
    scanf("%d", &k);
    vector<int> ret = process(inp, k); 
    for(int &a: ret) {
        printf("%d\n", a);
    }
    return 0;
}