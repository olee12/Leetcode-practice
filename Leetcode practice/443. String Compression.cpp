#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i  = 0, j = 0;
        while(i<chars.size()) {
            chars[index++] = chars[i];
            j = i;
            while(j<chars.size() && chars[j]==chars[i]) j++;
            int total = j - i;
            i = j;
            if(total < 2) continue;
            string totalStr = to_string(total);
            for(int i = 0; i<totalStr.size();i++) chars[index++] = totalStr[i];
        }
        return index;
    }
};


int main() {

}