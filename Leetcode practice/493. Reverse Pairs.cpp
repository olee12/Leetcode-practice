#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
int bit[2 * 50000 + 50] = {0};

void update(int index, int val, int n) {
    while(index <= n) {
        bit[index]+=val;
        index += index & -index;
    }
}
int query(int index) {
    int sum = 0;
    while(index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<double> st;
        unordered_map<double, int> dict;

        st.insert(numeric_limits<long long>::min());
        for(auto num: nums) {
            st.insert(num);
            st.insert((num - 1 )/2.0);
        }
        int idx = 0;

        for(auto n:st) {
            dict[n] = ++idx;
        }
        memset(bit, 0, sizeof(bit));
        long long ret = 0;
        for(int i = nums.size() - 1; i>=0; i--) {
            int &num = nums[i];
            int l = dict[(num - 1)/2.0];
                       //printf("%d dict[num]: %d (num-1)/2: %lf dict[(num-1)/2]: %d %d\n", num, dict[num], (num-1)/2.0, dict[(num-1)/2.0], query(l));
            ret += query(l);
            update(dict[num], 1, st.size() + 1);
        }
        return (int)ret;
    }
};


int main(int argc, char const *argv[])
{

    update(1, 1, 10);
    assert(query(10) == 1);
    update(9, 10, 10);
    assert(query(10)==11);
    update(5, -2, 10);
    assert(query(10) == 9);
    assert(query(4)==1);
    assert(query(5)==-1);


    Solution sol;

    vector<int> arr = {2,4,3,5,1};
    cout << sol.reversePairs(arr)<<endl;
    assert(sol.reversePairs(arr) == 3);

    return 0;
}
