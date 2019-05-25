#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp1(const string &st1, const string &st2) {
    return st1+st2 > st2+st1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int &num:nums){
            snums.push_back(to_string(num));
        }
        sort(snums.begin(),snums.end(),comp1);
        string ret = "";
        for(string &str:snums) ret+=str;
        if(ret.size()>0 && ret[0]=='0') return "0";
        return ret;
    }
};


int main() {
    vector<int> vec = {3,30,34,5,9};
    Solution sol;
    cout<<sol.largestNumber(vec)<<endl;
}

// "849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322281216213206020001921763154815181495141713801147114310901048"
// "849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048"