#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int p, int r) ;

void quickSort(vector<int> &vec, int p, int r) {
    if(p < r) {
        int q = partition(vec, p, r);
        cout << "p: "<<p<<" r: "<< r <<" q: "<<q<<" : vec[q]"<<vec[q]<<endl;
        for(auto it:vec) printf(" - %d ", it);
        cout << endl;
        quickSort(vec, p, q - 1);
        quickSort(vec, q + 1, r);
    }
}

int partition(vector<int> &vec, int p, int r) {
    int x = vec[r];
    int i = p - 1;
    // cout << "--- p: "<<p << " --- r: "<<r<<endl;
    for(int j = p;j<=r-1;j++) {
        if(vec[j] <= x) {
            i++;
            swap(vec[i], vec[j]);
        // cout << "i: "<<i << " j: "<<j <<endl;
        // for(auto it:vec) printf(" * %d ", it);
        // cout << endl;
        } 
    }
    swap(vec[i + 1], vec[r]);
    return i+1;
}


int main() {

    vector<int> vec = {1,1,1,1,1,1,1,1,1,1,1,1};
    quickSort(vec, 0, vec.size() - 1);
    printf("sorted: ");
    for(auto it:vec) printf("%d ", it);

    printf("\n");
}