#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==0 || k==0) return vector<int>();
        unordered_map<int,int> freq;
        vector< pair<int,int> > vec;

        for(int a:nums) freq[a]++;

        for(auto it:freq) vec.push_back(it);
        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){return a.second > b.second;});

        vector<int> ret(k,0);
        for(int i = 0;i<k;i++){
            ret.push_back(vec[i].first);
        }
        return ret;
    }
};

int main()
{

}