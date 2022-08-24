class lru
{
public:
    int key;
    int val;
    lru *prev;
    lru *next;

    lru() : key(-1), val(-1), prev(NULL), next(NULL)
    {
    }
};
class LRUCache
{
public:
    map<int, lru *> m;
    int cap;
    lru *head, *tail;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new lru();
        tail = new lru();

        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
    }

    int get(int key)
    {

        if (m.find(key) == m.end())
            return -1;

        int value = m[key]->val;

        lru *nn = m[key]->next;
        lru *pn = m[key]->prev;

        pn->next = nn;
        nn->prev = pn;

        lru *nN = new lru();
        nN->key = key;
        nN->val = value;

        lru *ptr = head->next;
        head->next = nN;
        nN->prev = head;
        nN->next = ptr;
        ptr->prev = nN;
        m[key] = nN;

        return nN->val;
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {

            lru *p = m[key]->prev;
            lru *nx = m[key]->next;
            p->next = nx;
            nx->prev = p;
        }

        if (m.size() == cap && m.find(key) == m.end())
        {
            lru *ptr = tail->prev->prev;
            lru *p = tail->prev;
            ptr->next = tail;
            tail->prev = ptr;
            m.erase(p->key);
        }

        lru *p = new lru();
        p->key = key;
        p->val = value;

        lru *hn = head->next;

        head->next = p;
        p->prev = head;
        p->next = hn;
        hn->prev = p;
        m[key] = p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */