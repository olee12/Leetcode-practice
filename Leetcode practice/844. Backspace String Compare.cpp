#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
       int lenS = normalize(S);
        int lenT = normalize(T);
        if(lenS != lenT) return false;
        int i = 0,j = 0;
        while(i<lenS && j < lenT){
            if(S[i] != T[j]) return false;
            i++;
            j++;
        }
        return true;
    }

    int normalize(string& S){
        int indx = 0;
        for(int i = 0;i<S.size();i++){
            if(S[i]=='#'){
                indx--;
            }else{
                indx = max(0,indx);
                S[indx] = S[i];
                indx++;
            }
        }
        return indx;
    }
};

int main()
{
    return 0;
}