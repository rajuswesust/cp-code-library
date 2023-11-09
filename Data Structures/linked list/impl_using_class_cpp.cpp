#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
    Node *head;
public:
    LinkedList() {
        head = NULL;
    }
    void insertNode(int);
    void deleteNode(int);
    void print();
    void reverseList();
    int length();
};
int LinkedList::length() {
    int len = 0;
    Node *curr = head;
    while(curr != NULL) {
       curr = curr ->next;
       len++;
    }
    return len;
}
void LinkedList::insertNode(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    } 
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    cout<<"insert node" <<endl;
}
void LinkedList::deleteNode(int ind) {
    //1 based indexing
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if(length() < ind) {
        cout << "index out of range!" << endl;
        return;
    }
    Node *curr = head, *prev;

    //deleting head
    if(ind == 1) {
        //cout << "deleting head!" << endl;
        head = head->next;
        delete curr;
        return;
    }
    while(ind > 1) {
        prev = curr;
        curr = curr->next;
        ind--;
    }
    prev->next = curr->next;
    delete curr;
}
void LinkedList::print() {
    Node *curr = head;
    cout << "printing list: ";
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void LinkedList::reverseList() {
    Node *prev = NULL, *next = NULL;
    Node *curr = head;

    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main() {
    LinkedList list;

    cout << "current length: " << list.length() << endl;

    list.insertNode(2);
    list.print();
    cout << "current length: " << list.length() << endl;

    list.insertNode(5);
    list.insertNode(8);
    list.print();
    cout << "current length: " << list.length() << endl;

    list.deleteNode(4);
    
    list.deleteNode(1);
    list.print();

    list.insertNode(10);
    list.insertNode(11);
    list.print();   //5 -> 8 -> 10 -> 11
    list.deleteNode(2); 
    list.print();   //5 -> 10 -> 11
    list.deleteNode(3);
    list.print(); //5 -> 10

    list.reverseList();
    list.print(); // 10 -> 5

    return 0;
}