#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        dict.clear();
        vec.clear();
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.find(val) != dict.end()) {
            return false;
        }
        vec.emplace_back(val);
        dict[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dict.find(val)==dict.end()) return false;
        int last = vec.back();
        int newLastPos = dict[val];
        vec[newLastPos] = last;
        dict[last] = newLastPos;
        vec.pop_back();
        dict.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];    
    }
    private:
    unordered_map<int, int> dict;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {
    RandomizedSet rset;
    
}