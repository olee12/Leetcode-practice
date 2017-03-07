#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	
    	sort(nums.begin(),nums.end());
    	int ret = 1<<30;
    	int current = 0,lft = 0,rght = 0,now;
    	int ans = 0;
    	int len = nums.size();
    	for(int i = 0;i<len;i++){
    		current = target - nums[i];
    		lft = i + 1;
    		rght = len - 1;
    		while(lft < rght){
    			now = nums[lft] + nums[rght];
    			if(now > current) {
    				if( now - current < ret ) {
    					ans = now + nums[i];
    					ret = now - current;
    				}
    				rght--;
    			}else if( now < current){
    				if(current - now < ret){ 
    					ans = now + nums[i];
    					ret = current - now;
    				}
    				lft++;
    			}else{
    				return target;
    			}
    		}
    	}
    	return ans;
    }
};

int main()
{
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	Solution ret;

	printf("%d\n",ret.threeSumClosest(v,-100) );
}