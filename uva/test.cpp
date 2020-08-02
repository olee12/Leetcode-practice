#include <bits/stdc++.h>
using namespace std;

int main()
{

    set < pair<int,int> > st;

    st.insert({7, 12});

    for (auto it : st ) {
        cout << it.first << ' ' << it.second << endl;
    }

    auto it = st.upper_bound({10,15});
    it--;
    if( it != st.end()) {
        cout << it->first<<endl;
    }
}