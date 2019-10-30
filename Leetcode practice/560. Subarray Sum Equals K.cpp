#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         map<int,int> freq;
         freq[0] = 1;
         vector<int> cumulative;
         int total = 0;
         for(int &num:nums) {
             total += num;
             cumulative.push_back(total);
         }
         int ret = 0;
        for(int &num: cumulative) {
            ret += freq[num-k];
            freq[num]++;
        }
        return ret;
    }
};

int main() {

}