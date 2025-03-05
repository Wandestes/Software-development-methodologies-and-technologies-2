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

    char deleteAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        Node* temp = head;
        if (index == 0) {
            head = head->next;
            if (head) head->prev = nullptr;
        }
        else {
            for (int i = 0; i < index; i++) temp = temp->next;
            temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            else tail = temp->prev;
        }
        char data = temp->data;
        delete temp;
        size--;
        return data;
    }

    void deleteAll(char element) {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            if (temp->data == element) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                size--;
            }
            temp = nextNode;
        }
    }

    char get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->data;
    }

    DoublyLinkedList* clone() {
        DoublyLinkedList* copy = new DoublyLinkedList();
        Node* temp = head;
        while (temp) {
            copy->append(temp->data);
            temp = temp->next;
        }
        return copy;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;
        tail = head;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) head = temp->prev;
    }

    int findFirst(char element) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == element) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int findLast(char element) {
        Node* temp = tail;
        int index = size - 1;
        while (temp) {
            if (temp->data == element) return index;
            temp = temp->prev;
            index--;
        }
        return -1;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void extend(DoublyLinkedList* other) {
        Node* temp = other->head;
        while (temp) {
            append(temp->data);
            temp = temp->next;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    std::cout << "Method: append" << std::endl;
    list.append('A');
    list.append('B');
    list.append('C');
    list.print();

    std::cout << "Method: insert" << std::endl;
    list.insert('D', 1);
    list.print();

    std::cout << "Method: deleteAt" << std::endl;
    std::cout << "Deleted: " << list.deleteAt(2) << std::endl;
    list.print();

    std::cout << "Method: deleteAll" << std::endl;
    list.deleteAll('A');
    list.print();

    std::cout << "Method: findFirst" << std::endl;
    std::cout << "FindFirst B: " << list.findFirst('B') << std::endl;

    std::cout << "Method: findLast" << std::endl;
    std::cout << "FindLast D: " << list.findLast('D') << std::endl;

    std::cout << "Method: clone" << std::endl;
    DoublyLinkedList* copy = list.clone();
    copy->print();

    std::cout << "Method: reverse" << std::endl;
    list.reverse();
    list.print();

    std::cout << "Method: extend" << std::endl;
    copy->extend(&list);
    copy->print();

    delete copy;
    return 0;
}
