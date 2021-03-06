#include <bits/stdc++.h>
using namespace std;


class Container {
public:
    vector<pair<char, int>> ci;
    int idx = 0;
    Container(){
        idx = 0;
        ci = vector<pair<char,int>>();
    }
    void add(pair<char,int> inp) {
        if (inp.second <=0) return ;
        ci.push_back(inp);
    }
    char get() {
        if (idx >= ci.size() || idx <0) return -1;
        char ch = ci[idx].first;
        ci[idx].second--;
        if (ci[idx].second==0) idx++;
        return ch;
    }
    bool isEmpty() {
        if (idx >= ci.size() || idx <0) return true;
        return false;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> freq;
        for(char ch: S) freq[ch]++;
        vector<pair<int,char>> f_char;
        for(auto it : freq) {
            f_char.push_back({it.second, it.first});
        }
        sort(f_char.begin(), f_char.end(), greater<pair<int,char>>());
        pair<int,char> &mx = f_char[0];
        int i = 1;
        Container *mx_container = new Container();
        mx_container->add({mx.second, mx.first});
        Container *second_container = new Container();
        int total = 0;
        for(;i<f_char.size();i++) {
            pair<int, char> &p = f_char[i];
            if (total + p.first >= mx.first-1) {
                second_container->add({p.second,mx.first -1 - total});
                p.first -= (mx.first - 1 - total);
                total = mx.first - 1;
                if(p.first == 0) i++;
                break;
            }else {
                total+= p.first;
                second_container->add({p.second, p.first});
            }
        }
        Container *other = new Container();
        for(;i<f_char.size();i++) {
            pair<int,char> &p = f_char[i]; 
            other->add({p.second, p.first});
        }

        if (total != mx.first - 1) {
            return "";
        }
        vector<char> ret;
        queue<Container*> q;
        q.push(mx_container);
        q.push(second_container);
        while(q.size()) {
            // cout<<"olee"<<endl;
            Container *c = q.front();
            q.pop();
            if(c->isEmpty()) continue;
            ret.push_back (c->get());
            // cout<<"\ni: "<<idx<<" c->get() "<<ret[idx-1]<<endl;
            q.push(c);
        }
        int nidx = 0;
        string tmp(ret.begin(), ret.end());
// cout<<"before other: "<< tmp<<endl;;
        for(char nxt = other->get(); nxt != -1; nxt = other->get()) {
            // cout<<"idx: "<< idx<< " nxt: "<<nxt<<endl;
            ret.insert(ret.begin()+nidx, nxt);
            nidx+=2;
            nidx%=ret.size();
        }

        string result(ret.begin(), ret.end());
        // cout<<"len of ret"<<ret.size()<<" result: "<<result<<endl;;
        return result;
    }
};



int main() {
    Solution sol;
    cout<<"aab: "<<sol.reorganizeString("aab")<<endl;
    cout<<"aaaaaabbccef: "<< sol.reorganizeString("aaaaaabbccef")<<endl;;
    cout<<"aaaaabbccef: "<< sol.reorganizeString("aaaaacef")<<endl;;
    cout<<"zhmyo: "<< sol.reorganizeString("zhmyo")<<endl;;
}

