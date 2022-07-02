#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    for(int i = 0;i<9;i++) {
        for(int j = 0;j<9;j++) {
            int k = i/3 * 3 + j/3;
            printf(" (i: %d, j: %d, k: %d) ", i, j, k);
        }
        printf("\n");
    }
    return 0;
}
