#include <bits/stdc++.h>
using namespace std;

char solve(string &str) {
    int n = str.size();
    int a = 0, b = 0;
    for(char ch: str) {
        if(ch=='A') a++;
    }
    
    b = n - a;

    if(abs(a-b)!=1) return 'N';
    return 'Y';
}

int main(int argc, char const *argv[])
{
    // freopen("../alchemy_input.txt", "r", stdin);
    // freopen("../alchemy_output.txt", "w", stdout);
    int test, cas = 1;
    scanf("%d", &test);
    while(test--){
        int n;
        string inp = "";
        scanf("%d", &n);
        for(int i = 0;i<n;i++){
            char ch;
            scanf(" %c", &ch);
            inp.push_back(ch);
        }
        printf("Case #%d: %c\n", cas++, solve(inp));
    }
    /* code */
    return 0;
}
