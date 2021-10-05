#include <bits/stdc++.h>
using namespace std;


class SparseVector {
public:
    unordered_map<int,int> m;   
    SparseVector(vector<int> &nums) {
	    m.clear();
       for(int i = 0;i<nums.size();i++) {
		if(nums[i] != 0) {
			m[i] = nums[i];
		}
       } 
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
	long long ret = 0;
	for(auto &it : this->m) {
	       if (vec.m.count(it.first)){
	   		ret += (long long) it.second * (long long) vec.m[it.first]; 
	       }
       } 
       return ret;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
