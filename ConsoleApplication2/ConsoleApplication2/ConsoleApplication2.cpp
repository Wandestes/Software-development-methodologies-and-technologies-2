#include <iostream>
#include <stdexcept>

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char data) : data(data), next(nullptr), prev(nullptr) {}
};

