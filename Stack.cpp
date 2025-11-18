#include "header.h"
#include <iostream>

Stack::Stack() : top(nullptr) {}

// Добавление элемента - O(1)
void Stack::push(const string& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

// Удаление элемента - O(1)
string Stack::pop() {
    if (top == nullptr) {
        cerr << "Stack is empty!" << endl;
        return "";
    }
    string value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

// Чтение стека - O(n)
void Stack::read() {
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}