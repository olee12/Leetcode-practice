#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> comb;
        if(rowIndex == 0) return comb;
        comb.push_back(1);
        for(int i = 1;i<rowIndex;i++){
            comb.push_back(0);
            for(int i = comb.size() - 1; i>=1;i--) comb[i] = comb[i] + comb[i-1];
        }
        return comb;
    }
};


int main() {

}