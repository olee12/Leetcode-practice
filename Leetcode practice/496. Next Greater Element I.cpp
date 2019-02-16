#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.size()==0) return ret;

        stack<int> st;
        unordered_map<int,int> dict;
        dict.clear();
        for(int i = nums.size()-1;i>=0;i--){
            if(st.size()==0) {
                st.push(nums[i]);
            }else {
                while(st.size() && st.top() <= nums[i]) st.pop();
                if(st.size()) dict[nums[i]] = st.top();
                st.push(nums[i]);
            }
        }

        for(int &key:findNums){
            if(dict.count(key)==0) ret.push_back(-1);
            else ret.push_back(dict[key]);
        }
        return ret;
    }
};

int main(){

}