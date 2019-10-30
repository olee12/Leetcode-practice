#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 100001;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int range = 2 * maxn + 5;
        vector< set<int> > line( range , set<int>());
        range = 0;
        for(int i = 0;i<nums.size();i++) {
            vector<int> &vec = nums[i];
            for(int &a : vec) {
                line[a+maxn].insert(i);
                range = max(range, a + maxn);
            }
        }
        range++;

        int start = 0, end = 0;
        int ans = 3 * maxn;
        int i = 0, j = 0;
        int sum = 0;
        vector<int> freq(line.size(), 0);
        unordered_map<int,bool> st;
        
        while(j < range) {
            
            for(auto it:line[j]) {
                st[it] = true;
                freq[it]++;
            }
            j++;
            while(i < range && st.size() >= nums.size()) {
                if(ans > j - i) {
                    ans = j - i;
                    start = i - maxn;
                    end = j - maxn;
                }
                for(auto it:line[i]) {
                    freq[it]--;
                    if(freq[it]==0){
                        st.erase(it);
                    }
                }
                i++;
            }
        }
        return {start, end-1};
    }
};

int main()
{
    vector<vector<int>> nums = {{-73, -70, 15, 36, 51, 52}, {22, 44, 58, 60, 61}, {-61, 12, 21, 22, 23, 23, 25, 29}, {-27, -12, 1, 4, 18, 18, 18, 19}, {-1, 57, 58, 60, 69, 72, 73}, {13, 16, 41, 54, 88, 88, 89, 92}, {-16, 35, 39, 39, 43, 46}, {-16, 32, 35, 49, 54, 63}, {25, 49, 61, 68, 71}, {67, 88, 88, 90, 90, 90, 91}};
    Solution sol;
    for (int &r : sol.smallestRange(nums))
    {
        printf(" [ %d ] ", r);
    }
}