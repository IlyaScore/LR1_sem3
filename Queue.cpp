#include "header.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {}

// Добавление элемента - O(1)
void Queue::push(const string& value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Удаление элемента - O(1)
void Queue::pop() {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

// Чтение очереди - O(n)
void Queue::read() {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}