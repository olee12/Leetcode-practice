#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    class Compare{
        public:
        bool operator () (pair<string,int> a,pair<string,int> b){
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret;

        if(k==0) return ret;

        map<string, int> dict;
        for(string &word:words)
            dict[word]++;
        
        priority_queue<pair<string,int>,vector < pair<string,int> > , Compare> q;

        for(auto it = dict.begin(); it != dict.end(); it++){
            q.push(*it);
            if(q.size()>k)
                q.pop();
            cout<<"top: "<<q.top().first<<' '<<q.top().second<<endl;
        }

        cout<<"ans: "<<endl;
        while(q.size()){
            ret.push_back(q.top().first);
            cout<<q.top().first<<' '<<q.top().second<<endl;
            q.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main() {
    Solution sol; 
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    sol.topKFrequent(words,4);
}