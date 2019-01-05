#include <iostream>
#include <vector>
#include <set>
using namespace std;


class ExamRoom {
public:
    int N;
    set<int> st;
    ExamRoom(int N) {
        this->N = N;
        st.clear();
    }
    
    int seat() {
        
        int pos = 0;

        if(st.size()){
            int prev = -1;
            int dist = *(st.begin());
            for(auto cur:st){
                if(prev != -1){
                    int d = (cur - prev)/2;
                    if(d>dist){
                        dist = d;
                        pos = prev + d;
                    }
                }
                prev = cur;
            }
            if(N - 1 - *(st.rbegin()) > dist) pos = N - 1;
        }
        st.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};



int main()
{
    ExamRoom room(10);

    printf("----> %d\n",room.seat());
    printf("----> %d\n",room.seat());
    printf("----> %d\n",room.seat());
    printf("----> %d\n",room.seat());
    room.leave(4);
    printf("----> %d\n",room.seat());
    printf("----> %d\n",room.seat());
    return 0;
}