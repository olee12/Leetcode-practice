#include <bits/stdc++.h>

using namespace std;


vector< string > solve(vector<bool> &in, vector<bool> &out) {
    int n = in.size();
    vector<vector<bool>> adj(n, vector<bool>(n, 0));
    
    for(int i = 0;i<n;i++) adj[i][i] = true;

    for (int i = 0;i<n-1;i++){
        int j = i+1;
        if(out[i] && in[j]) adj[i][j] = true;
        if(out[j] && in[i]) adj[j][i] = true;
    }

    for(int i = 0;i<n;i++) 
        for(int j = 0;j < n;j++) 
            for(int k = 0; k < n; k ++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
    
    vector<string> result;
    for(int i = 0;i<n;i++) {
        string ret = "";
        for(int j = 0;j<n;j++){
            ret.push_back(adj[i][j]?'Y':'N');
        }
        result.push_back(ret);
    }
    return result;

}


int main(int argc, char const *argv[])
{
    freopen("../travel_restrictions_input.txt", "r", stdin);
    freopen("../travel_restrictions_output.txt", "w", stdout);
    
    int test, n, cas = 1;
    scanf("%d", &test); 
    // printf("%d\n",test);
    while(test--) {
        scanf("%d", &n);
        // printf("n == %d\n", n);
        vector<bool> in(n, 0);
        vector<bool> out(n, 0);
        for(int i = 0; i<n;i++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == 'Y') in[i] = true;
        }
        for(int i = 0;i<n; i++) {
            char ch;
            scanf(" %c", &ch);
            if(ch == 'Y') out[i] = true;
        }

        vector<string> result = solve(in, out);

        printf("Case #%d: \n", cas++);
        for(int i = 0;i<result.size();i++) {

            printf("%s\n", result[i].c_str());
        }
    }


    return 0;
}
