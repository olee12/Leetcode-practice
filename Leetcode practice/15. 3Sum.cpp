#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;
typedef std::vector<pii> vpii;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int> > ret;
		for(int i = 0;i<nums.size();i++){
			int rem = -1*nums[i];

			int lft = i + 1;
			int rght = nums.size()-1;

			while(lft < rght){

				int sum = nums[lft] + nums[rght];

				if(sum > rem) rght--;
				else if(sum < rem) lft++;
				else{
					std::vector<int> tmp;
					tmp.clear();
					tmp.push_back(nums[i]);
					tmp.push_back(nums[lft]);
					tmp.push_back(nums[rght]);

					while(lft < rght && nums[lft]==tmp[1]) lft++;
					while(lft < rght && nums[rght]==tmp[2]) rght--;
					ret.push_back(tmp);
				}

				while(i<nums.size()-1 && nums[i+1]==nums[i]) i++;

			}

		}

		return ret;
    }
};

int main()
{

}