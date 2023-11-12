#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> ump;

    LRUCache(int cap) {
        this->cap = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode) {
        //add newNode after head
        Node *nextNode = head->next;
        newNode->prev = head;
        newNode->next = nextNode;
        head->next = newNode;
        nextNode->prev = newNode;
    }

    void deleteNode(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if(!ump.count(key))
            return -1;
        Node *node = ump[key];
        ump.erase(key);
        deleteNode(node);
        addNode(node);
        ump.insert({key, head->next});

        return node->val;
    }

    void put(int _key, int _val) {
        Node *newNode = new Node(_key, _val);

        //if the key already exists have to update in the doubly linked-list
        //delete that existing node
        //add it after head
        //update the pointer of key in the map
        if(ump.find(_key) != ump.end()) {
            deleteNode(ump[_key]);
            addNode(newNode);
        }
        else if(ump.size() == cap) {
            cout << "cache full!" << endl;
            cout << "deleting least used node: " << tail->prev->key << ", " << tail->prev->val << endl;
            ump.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(newNode);
        }
        else {
            addNode(newNode);
        }
        ump[_key] = head->next;
    }
    void print() {
        Node *curr = head->next;
        cout << "current list: " << endl;
        while(curr != tail) {
            cout << curr->key << ": " << curr->val << endl;
            curr = curr->next;
        }
        cout << "current map: " << endl;
        for(auto it: ump) {
            cout << it.first << ": " << it.second << endl;
        }
    }
};
int main() {
    LRUCache *cache = new LRUCache(3);

    cache->put(1, 10);
    cache->put(2, 9);
    cout << cache->get(3) << endl;

    cache->put(3, 4);
    cache->put(5, 4);
    cache->print();
    cout << cache->get(1) << endl;
    cache->put(7, 6);
    cache->print();
    cout << cache->get(3) << endl;
    cache->print();
}
