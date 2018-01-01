#include <bits/stdc++.h>
using namespace std;

class ListNodeD
{
  public:
    int key;
    int value;
    ListNodeD(int key, int val)
    {
        this->key = key;
        this->value = val;
        next = NULL;
        prv = NULL;
    }
    ListNodeD *next;
    ListNodeD *prv;
};

class LRUCache
{
  public:
    int _capacity;
    map<int, ListNodeD *> dict;
    ListNodeD *head;
    ListNodeD *tail;
    int count;

    LRUCache(int capacity)
    {
        this->_capacity = capacity;
        dict.clear();
        this->count = 0;
        head = new ListNodeD(0, 0);
        tail = new ListNodeD(0, 0);
        head->prv = NULL;
        tail->next = NULL;
        head->next = tail;
        tail->prv = head;
    }

    int get(int key)
    {
        auto it = dict.find(key);
        if (it == dict.end())
        {
            return -1;
        }
        ListNodeD *node = dict[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        auto it = dict.find(key);
        if (it == dict.end())
        {
            ListNodeD *node = new ListNodeD(key, value);

            insertFront(node);
            dict[key] = node;
            ++count;

            if (count > _capacity)
            {
                ListNodeD *del = tail->prv;
                removeNode(del);
                dict.erase(del->key);
            }
        }
        ListNodeD *node = dict[key];
        node->value = value;
        moveToHead(node);
    }

    void insertFront(ListNodeD *node)
    {

        ListNodeD *tmp = head->next;
        head->next = node;
        node->prv = head;
        node->next = tmp;
        tmp->prv = node;
    }

    void removeNode(ListNodeD *node)
    {
        ListNodeD *back = node->prv;
        ListNodeD *front = node->next;
        back->next = front;
        front->prv = back;
    }

    void moveToHead(ListNodeD *node)
    {
        removeNode(node);
        insertFront(node);
    }

    int removeTail()
    {
        int key;
        ListNodeD *del = tail->prv;
        ListNodeD *a = del->prv;
        //delete del;
        a->next = tail;
        tail->prv = a;
        return del->value;

    }
};

int main()
{
    LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    printf("%d\n",cache.get(1));    // returns 1
    cache.put(3, 3); // evicts key 2
    printf("%d\n",cache.get(2));     // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    printf("%d\n",cache.get(1));     // returns -1 (not found)
    printf("%d\n",cache.get(3));     // returns 3
    printf("%d\n",cache.get(4));     // returns 4
}