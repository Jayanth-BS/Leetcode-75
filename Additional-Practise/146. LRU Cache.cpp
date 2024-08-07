// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

//     LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//     int get(int key) Return the value of the key if the key exists, otherwise return -1.
//     void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

class LRUCache {           //O(1)
public:
    class node{
    public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };
    unordered_map<int,node*> map;
    int cap;

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    };
    
    void deletenode(node * temp){
        node* delnext = temp->next;
        node* delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }

    void addnode(node* temp){
        node* nextone = head->next;
        temp->next = nextone;
        head->next = temp;
        temp->prev = head;
        nextone->prev= temp;
    }

    int get(int key) {
        if(map.find(key)!= map.end()){
            int res = map[key]->val;
            node* del = map[key];
            map.erase(key);
            deletenode(del);
            addnode(del);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            node* temp = map[key];
            map.erase(key);
            deletenode(temp);
        }
        if(map.size()==cap){
            map.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode( new node(key,value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
