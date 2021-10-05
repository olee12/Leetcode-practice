#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> infos;
        for (int i = 0; i < keyName.size(); i++) {
            int h, m;
            char sep;
            sscanf(keyTime[i].c_str(), "%d%c%d", &h, &sep, &m);
            // printf("%d %d %c\n", h, m, sep);
            infos[keyName[i]]
                .push_back(h * 60 + m);
        }
        // sort(infos.begin(), infos.end());
        vector<string> ret;
        for (auto& person : infos) {
            deque<int> dq;
            sort(person.second.begin(), person.second.end());
            for (auto t : person.second) {
                if (dq.size() == 0) {
                    dq.push_back(t);
                } else {
                    // printf("%s %d %d\n", person.first.c_str(), dq.front(), t);
                    while (dq.size() && (t - dq.front() > 60)) {
                        dq.pop_front();
                    }
                    dq.push_back(t);
                    if (dq.size() >= 3) {
                        ret.push_back(person.first);
                        break;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    /* code */
    vector<string> keyName = {"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"};
    vector<string> keyTime = {"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"};
    Solution sol;
    for (auto it : sol.alertNames(keyName, keyTime)) {
        cout << it << endl;
    }
    return 0;
}
