#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 1000;
struct Person {
    string first;
    string last;
    bool full;
};

Person persons[maxn];

char f[maxn],s[maxn];

int main() {
    int t;
    int n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        map<string,int> dict;
        dict.clear();
        for(int i = 0;i<n;i++){
            scanf("%s %s",f,s);
            dict[f]++;
            persons[i].first = f;
            persons[i].last = s;
            persons[i].full = false;
        }

        for(int i = 0;i<n;i++){
            if(dict[persons[i].first]>1){
                printf("%s %s\n",persons[i].first.c_str(),persons[i].last.c_str());
            }else {
                printf("%s\n",persons[i].first.c_str());
            }
        }
    }
    return 0;
}