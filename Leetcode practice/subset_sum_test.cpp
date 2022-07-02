#include <iostream>
using namespace std;

string binary(int p, int s) {
    int pw = (1 << s) - 1;
    string tmp = "";
   while(pw) {
      tmp.push_back('0');
      pw>>=1; 
    }

    for(int i = tmp.size() - 1;i>=0;i--) {
        if(p & (1<<i)) tmp[i] = '1';
    }
    
    return {tmp.rbegin(), tmp.rend()};
}

void printSubSet(int mask, int s) {
        for(int p = (mask - 1) & mask; p > 0;p = (p - 1) & mask) {
            
            cout << "\t"<< binary(p, s) << endl;

        }
}


void printSubSetOptimized(int mask, int s) {
        for(int p = (mask - 1) & mask; p > (mask ^ p); p = (p - 1) & mask) {
            cout << "\t"<< binary(p, s) << endl;
            cout << "\t" << binary(p^mask, s) <<endl;
            cout <<endl;
        }
}

void printSubSetOfSubSet(int s) {
    int limit = (1 << s) - 1;

    for(int mask = 0;mask <= limit;mask++) {
        cout << "mask: "<< mask<< " binary: "<<binary(mask, s)<<endl;;
        cout << "sub set list"<<endl;
        printSubSetOptimized(mask, s); 
    }
}




int main(int argc, char const *argv[])
{
    printSubSetOfSubSet(5);
    /* code */
    return 0;
}
