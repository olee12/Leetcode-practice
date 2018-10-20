#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int prv = A[0];
        int indx = -1;
        int change = 0;
        int i = 1;
        while(i < A.size()){
            int cur = A[i];

            if(!change && A[i] < prv){
                change = 1;
                indx = i-1;
            }
            else if(change==1 && A[i] > prv){
                indx = -1;
                break;
            }
            prv = cur;
            i++;
        }
        return indx;
    }
};

int main()
{

}