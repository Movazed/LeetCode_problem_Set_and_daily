// LRU Cache implementation using unordered_map + doubly linked list
#define all(x) x.begin(), x.end()
using ll = long long;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    // Move node to front (most recently used)
    void moveToFront(Node* node) {
        // Remove node
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // Insert after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            moveToFront(node);
            return;
        }
        if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            lru->prev->next = tail;
            tail->prev = lru->prev;
            delete lru;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        // Insert after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
};

/*
Algorithm:
- Doubly linked list for order, unordered_map for O(1) access.
- On get/put, move node to front.
- On overflow, evict tail->prev (LRU).
Time: O(1) per get/put
Space: O(capacity)
Dry run:
put(1,1), put(2,2), get(1) -> 1, put(3,3) (evicts 2), get(2) -> -1, put(4,4) (evicts 1), get(1) -> -1, get(3) -> 3, get(4) -> 4
*/