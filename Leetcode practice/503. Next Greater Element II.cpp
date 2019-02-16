#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr;
        arr.insert(arr.end(),nums.begin(),nums.end());
        arr.insert(arr.end(),nums.begin(),nums.end()); 
        stack<int> st;
        vector<int> dict(nums.size(),-1);
        
        for(int i = arr.size()-1;i>=0;i--){
            while(st.size() && arr[st.top()]<=arr[i]) st.pop();
            if(st.size() && i<nums.size())  dict[i] = arr[st.top()];
            st.push(i);
        }
        return dict;
    }
};


int main(){
    Solution sol;
    vector<int> v = {};
    vector<int> ret = sol.nextGreaterElements(v);
    for(int &a:ret){
        cout<<a<<' ';
    }
    return 0;
}