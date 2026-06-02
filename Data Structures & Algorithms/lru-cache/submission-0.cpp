class Node{
public:
   int key,value;
   Node *next;
   Node *prev;
   Node(int key,int value){
    this->key=key;
    this->value=value;
    next=nullptr;
    prev=nullptr;
   }
};
class LRUCache {
public:
    int capacity;
    Node *left;
    Node *right;
    unordered_map <int,Node*>cache;
    LRUCache(int capacity) {
        this->capacity=capacity;
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        if(cache.count(key)){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    void remove(Node *node){
       Node *p=node->prev;
       Node *n=node->next;
       p->next=n;
       n->prev=p;
    }
    void insert(Node *node){
       Node *p1=right->prev;
       Node *r1=right;
       p1->next=node;
       node->prev=p1;
       node->next=r1;
       r1->prev=node;
    }
    void put(int key, int value) {
        if(cache.count(key)){
            remove(cache[key]);
        }
        cache[key]=new Node(key,value);
        insert(cache[key]);
        if(cache.size()>capacity){
            Node *lru=left->next;
            remove(lru);
            cache.erase(lru->key);

        }
    }
};
