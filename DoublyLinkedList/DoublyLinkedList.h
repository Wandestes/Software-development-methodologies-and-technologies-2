// DoublyLinkedList.h
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(int value);
    void display() const;
};

#endif
