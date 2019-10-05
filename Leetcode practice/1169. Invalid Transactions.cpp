#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

template <class Container>
void split2(const std::string &str, Container &cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim))
    {
        cont.push_back(token);
    }
}

class transaction
{
public:
    string name, city;
    int time;
    int ammount;
    transaction(string n, string c, int t, int a) : name(n), city(c), time(t), ammount(a) {}
    bool operator<(const transaction &p) const
    {
        return time < p.time;
    }
    bool operator>(const transaction &p) const
    {
        return time > p.time;
    }
    bool operator==(const transaction &p) const
    {
        return time == p.time;
    }
    void print() const
    {
        printf("trans[name: %s, city: %s, time: %d, ammount: %d]\n", this->name.c_str(), this->city.c_str(), this->time, this->ammount);
    }
};
// without lower bound sol is faster and uses less memory
class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<vector<string>> tokens;
        for (string &str : transactions)
        {
            vector<string> t;
            split2(str, t, ',');
            tokens.push_back(t);
        }
        vector<transaction> trans;
        map<string, map<string, multiset<transaction>>> name_city;

        for (auto &tok : tokens)
        {
            transaction t = transaction(transaction(tok[0], tok[3], stoi(tok[1]), stoi(tok[2])));
            // printf("%d, %d\n",stoi(tok[1]), stoi(tok[2]));
            trans.push_back(t);
            // t.print();
            name_city[t.name][t.city].insert(t);
        }

        vector<bool> flag(transactions.size(), false);
        vector<string> ret;
        // for all transaction
        for (int i = 0; i < trans.size(); i++)
        {
            transaction &t = trans[i];
            if (t.ammount > 1000)
                flag[i] = true;
            // find invalid
            // printf("myt: ");
            // t.print();
            for (auto &mst : name_city[t.name])
            {
                if (mst.first == t.city)
                    continue;
                auto st = mst.second;
                multiset<transaction>::iterator it = st.lower_bound(t);
                if (it == st.end())
                {
                    it--;
                }

                // it->print();
                if (abs(it->time - t.time) <= 60)
                {
                    flag[i] = true;
                    continue;
                }
                if (it != st.begin())
                {
                    it--;
                }
                if (abs(it->time - t.time) <= 60)
                {
                    flag[i] = true;
                    continue;
                }
            }
        }
        for (int i = 0; i < flag.size(); i++)
        {
            if (flag[i] == false)
                continue;
            char str[100];
            transaction &t = trans[i];
            sprintf(str, "%s,%d,%d,%s", t.name.c_str(), t.time, t.ammount, t.city.c_str());
            ret.push_back(str);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> inp = {"alice,20,800,mtv", "alice,50,100,beijing"};

    Solution sol;

    vector<string> ret = sol.invalidTransactions(inp);
    for (string &str : ret)
    {
        cout << str << endl;
    }
    return 0;
}
