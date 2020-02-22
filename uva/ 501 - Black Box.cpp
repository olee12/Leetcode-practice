#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    multiset<int> st;

    auto it = st.begin();

    st.insert(1);
    cout<<"it: "<<*it<<endl;

    st.insert(2);
    it++;
    cout<<"\nit: "<<*it<<endl;
    st.insert(3);
    st.insert(3);
    st.insert(4);
    it++;
    it++;
    cout<<"\nit: "<<*it<<endl;
    it++;
    cout<<"\nit: "<<*it<<endl;
    st.insert(-1);
    cout<<"\nit: "<<*it<<endl;
    st.insert(-2);
    cout<<"\nit: "<<*it<<endl;
    // it++;
    // cout<<"\nit: "<<*it<<endl;

    for(auto it : st) {
        printf(" %d", it);
    }
    printf("\n");

    return 0;
}
