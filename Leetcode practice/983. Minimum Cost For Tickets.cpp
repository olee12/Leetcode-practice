#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 366;
map<int,bool> dict;
int dp[maxn];
vector<pair<int,int> > costs;
int rec(int day) {
    if(day >= maxn){
        return 0;
    }
    int &ret = dp[day];
    if(ret != -1) return ret;
    ret = numeric_limits<int>::max();
    for(pair<int,int> &cost:costs){
        for(int i = 1;i<=cost.first;i++) {
            ret = min(ret,rec(day+i)+cost.second);
        }
    }
    if(dict[day]==false){
        ret = min(ret,rec(day+1));
    }
    return ret;
}

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cst) {
        memset(dp,-1,sizeof(dp));
        dict.clear();
        costs.clear();
        for(int &day:days){
            dict[day] = true;
        }

        
        costs.push_back(make_pair(1,cst[0]));
        costs.push_back(make_pair(7,cst[1]));
        costs.push_back(make_pair(30,cst[2]));
        return rec(1);
    }
};


int main(){
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> cst = {2,7,15};

    Solution sol;

    cout<<"result : "<<sol.mincostTickets(days,cst)<<endl;

    return 0;
}