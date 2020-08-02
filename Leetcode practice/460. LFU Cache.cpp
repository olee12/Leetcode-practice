#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
    int key,val;
    Node *next, *prev;
    Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {};
};


class Chain {
    public:
    Node *head;
    Node *tail;
    int capacity;
    map<int, Node*> cache;
    Chain() {
        cache.clear();
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
    }
    Node* get(int key) {
        if(cache.find(key)==cache.end()) {
            return NULL;
        }
        return cache[key];
    }
    Node* add(int key, int val) {
        auto it = get(key);
        if(it != NULL) {
            it->val = val;
            return it;
        }
        Node *node = new Node(key, val);
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
        cache[key] = node;
        return node;
    }
    Node* add(Node *node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
        cache[node->key] = node;
        return node;
    }
    Node* removeLastNode() {
        return this->remove(tail->prev);
    }
    Node* lastNode() {
        return tail->prev;
    }
    Node* remove(int key) {
        auto it = get(key);
        if(it == NULL) return it;
        // cout <<"[removing "<<key<<"]\n";
        return remove(it);
    }
    Node* remove(Node *node) {
        
        // cout << "remvoing "<<node->key<<" "<< (node->next == tail) << (node->prev == head)<<"chain size : " <<size()<< endl;
        Node *p = node->prev;
        Node *n = node->next;
        p->next = n;
        n->prev = p;
        cache.erase(node->key);
        return node;
    }
    int size() {
        return cache.size();
    }
    void debug() {
        printf("[");
        for(Node *i = head->next; i!=tail;i = i->next) {
            printf(" {%d,%d}", i->key, i->val);
        }
        printf(" ~~~");
        for(Node *i = tail->prev;i != head;i = i->prev) {
            printf(" {%d,%d}", i->key, i->val);
        }
        printf(" ]\n");
    }
};

class LFUCache {
public:
    Chain *line;
    map<int,int> frequency;
    map<int,Chain*> bucket;
    int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
        line = new Chain();
        frequency.clear();
        bucket.clear();
    }
    
    int get(int key) {
        auto node = line->get(key);
        if(node == NULL) {
            return -1;
        }
        increaseFreq(key);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(line->size()==capacity && line->get(key) == NULL) {
            int low = lowestFrequent();
            // cout << "low--> "<<low<<endl;
            line->remove(low);
            deleteFreq(low);
        }
        Node* node = line->add(key,value);
        increaseFreq(key);
        // cout << "okay\n" << endl;
    }
    void addNewFreq(int key) {
        frequency[key] = 1;
        
        Chain *c;
        if(bucket.find(1) == bucket.end()) {
            c = new Chain();
            bucket[1] = c;
        }else {
            c = bucket[1];
        }
        c->add(key,-1);
        // cout << "adding new freq < key "<<key<<" ";
        // bucket[1]->debug();

    }
    void increaseFreq(int key) {
        if(frequency.find(key) == frequency.end()) {
            return addNewFreq(key);
        }

        int freq = frequency[key];
        frequency[key] = freq + 1;

        Chain *firstChain = bucket[freq];
        // cout << "increase --> "<<key<< "freq "<<freq << " first chan";
        // cout << "before remove: "<<endl;
        // firstChain->debug();
        Node *node = firstChain->remove(key);
        // cout << "after remove"<< endl;
        // firstChain->debug();
        // cout << "removed node "<< "key "<< node->key << " value: "<<node->val<<" chan size "<<firstChain->size()<<endl;;
        if(firstChain->size()==0) {
            bucket.erase(freq);
        }

        freq = freq + 1;
        Chain *secondChain;
        if(bucket.find(freq) == bucket.end()) {
            secondChain = new Chain();
            bucket[freq] = secondChain;
        }else {
            secondChain = bucket[freq];
        }
        secondChain->add(node);
        // cout << "second chain ";
        // secondChain->debug();
    }

    void deleteFreq(int key) {
        int freq = frequency[key];
        frequency.erase(key);
        // cout << "ok|\n";
        Chain *c = bucket[freq];
        c->remove(key);
        if(c->size() == 0) {
            bucket.erase(freq);
        }
    }

    int lowestFrequent() {
        auto low = bucket.begin();
        // cout << "low-key "<<low->first<<endl;
        // cout<< "low-key-size "<<low->second->size()<<endl;
        // low->second->debug();
        return low->second->lastNode()->key;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(int argc, char const *argv[])
{
    LFUCache *cache = new LFUCache(0 /* capacity */);

    cache->put(0,0);
    // cache->put(2, 2);
    assert(cache->get(0)==0);    // returns 1
    // cache->put(3, 3); // evicts key 2
    // assert(cache->get(2)==-1);    // returns -1 (not found)
    // assert(cache->get(3)==3);    // returns 3.
    // cache->put(4, 4); // evicts key 1.
    // assert(cache->get(1) == -1);    // returns -1 (not found)
    // assert(cache->get(3) == 3);    // returns 3
    // assert(cache->get(4) == 4);    // returns 4
    return 0;
}
