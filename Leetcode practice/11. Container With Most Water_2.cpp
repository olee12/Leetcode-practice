#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right) {
            int h = min(height[left], height[right]);
            int area = (right - left) * h;
            if (area > ret) ret = area;
            if (height[left]>height[right]) right--;
            else if (height[left] < height[right]) left++;
            else left++, right--;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> hight = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(hight)<< "\n";
    return 0;
}
