#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class TopVotedCandidate {
public:
    vector<int> ret;
    vector<int> persons;
    vector<int> times;
    TopVotedCandidate(vector<int> per, vector<int> tim) {
        persons = per;
        times = tim;
        ret.clear();
        vector<int> votes = vector<int>(persons.size()+5,0);
        int mx = -1;
        for(int i = 0;i<times.size();i++){
            const int &freq = (votes[persons[i]]++);
            cout<<"freq: "<<freq<<endl;
            if(freq >= mx){
                mx = freq;
                ret.push_back(persons[i]);
            }else{
                ret.push_back(ret[i-1]);
            }
        }
    }
    
    int q(int t) {
        int indx = lower_bound(times.begin(),times.end(),t) - times.begin();
        if(indx >= times.size() || times[indx]>t) indx--;
        return ret[indx];
    }
};

int main()
{
    //vector<int> ret = vector<int> (-1,100);
    vector<int> persons = {0,1,1,0,0,1,0};
    vector<int> times = {0,5,10,15,20,25,30};

    TopVotedCandidate obj =  TopVotedCandidate(persons,times);
    int t;
    while(cin>>t){
        cout<<"and : "<<obj.q(t)<<endl;
    }

    return 0;
}