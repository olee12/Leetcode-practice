#include <bits/stdc++.h>
using namespace std;

    struct Task {
        char name;
        int remaining;
        int next;
        Task(char n, int r, int t){
            this->name = n;
            this->remaining = r;
            this->next = t;
        }
    };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> dict;
        dict.clear();
        for (auto it : tasks) dict[it]++;
        queue<Task> q;

        for(auto it : dict) {
            q.push(Task(it.first, it.second, 1));
        }

        int current_time = 1;
        while(q.size()) {
            Task t = q.front();
            q.pop();
            cout <<"ct: "<<current_time<< " "<< t.name<< " "<< t.next << " "<< t.remaining<<"\n";
            if (t.next > current_time) {
                current_time += (t.next - current_time);
            }
            t.remaining--;
            if (t.remaining > 0){
                t.next = t.next + n + 1;
                q.push(t);
            }
            current_time++;
        }  
        return current_time-1;
    }
};




int main(int argc, char const *argv[])
{
    vector<char> task = {};
    int n = 2;
    Solution *sol = new Solution();
    cout << "result: "<< (sol->leastInterval(task, n))<<endl;
    return 0;
}
