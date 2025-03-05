#include <iostream>
#include <stdexcept>

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() { clear(); }

    int length() { return size; }

    void append(char element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(char element, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Invalid index");
        }
        Node* newNode = new Node(element);
        if (index == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        }
        else if (index == size) {
            append(element);
            return;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        size++;
    }
