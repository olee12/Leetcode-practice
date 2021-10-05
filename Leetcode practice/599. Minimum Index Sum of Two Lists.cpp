#include <bits/stdc++.h>>
using namespace std;

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> dict;
        for (int i = 0; i < list2.size(); i++) dict[list2[i]] = i;
        vector<string> ret;
        int mx = numeric_limits<int>::max();
        for (int i = 0; i < list1.size(); i++) {
            string& word = list1[i];
            if (dict.find(word) == dict.end()) continue;
            if (i + dict[word] < mx) {
                mx = i + dict[word];
                ret = {word};
            } else if (i + dict[word] == mx) {
                ret.push_back(word);
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
