#include "header.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор для освобождения памяти - O(n)
LinkedList::~LinkedList() {
    destroy();
}

// Уничтожение списка - O(n)
void LinkedList::destroy() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

// Добавление в начало - O(1)
void LinkedList::pushHead(const string& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}

// Добавление в конец - O(1) (благодаря tail)
void LinkedList::pushTail(const string& value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode;
}

// Добавление после индекса - O(n) в худшем случае
void LinkedList::pushAfterIndex(int index, const string& value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
    
    if (current == tail) {
        tail = newNode;
    }
}

// Добавление перед индексом - O(n) в худшем случае
void LinkedList::pushBeforeIndex(int index, const string& value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (index == 0) {
        pushHead(value);
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        prev = current;
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr && currentIndex != index) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    Node* newNode = new Node(value);
    prev->next = newNode;
    newNode->next = current;
}

// Удаление из начала - O(1)
void LinkedList::popHead() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    string value = temp->data;
    head = head->next;
    
    if (head == nullptr) {
        tail = nullptr;
    }
    
    delete temp;
}

// Удаление из конца - O(n) (нужно найти предпоследний элемент)
void LinkedList::popTail() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (head->next == nullptr) {
        string value = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    
    string value = current->next->data;
    delete current->next;
    current->next = nullptr;
    tail = current;
    cout << "Element '" << value << "' removed from the end of the list" << endl;
}

// Удаление после индекса - O(n)
void LinkedList::popAfterIndex(int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr || current->next == nullptr) {
        cout << "Cannot remove element after index " << index << "!" << endl;
        return;
    }
    
    Node* temp = current->next;
    string value = temp->data;
    current->next = current->next->next;
    
    if (temp == tail) {
        tail = current;
    }
    
    delete temp;
}

// Удаление перед индексом - O(n)
void LinkedList::popBeforeIndex(int index) {
    if (head == nullptr || index <= 0) {
        cout << "Cannot remove element before index " << index << "!" << endl;
        return;
    }
    
    if (index == 1) {
        popHead();
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    Node* prevPrev = nullptr;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        prevPrev = prev;
        prev = current;
        current = current->next;
        currentIndex++;
    }
    
    if (currentIndex != index || prevPrev == nullptr) {
        cout << "Cannot remove element before index " << index << "!" << endl;
        return;
    }
    
    string value = prev->data;
    prevPrev->next = current;
    delete prev;
}

// Удаление по значению - O(n)
void LinkedList::popByValue(const string& value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (head->data == value) {
        popHead();
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "Element with value '" << value << "' not found!" << endl;
        return;
    }
    
    prev->next = current->next;
    
    if (current == tail) {
        tail = prev;
    }
    
    delete current;
}

// Поиск по значению - O(n)
void LinkedList::findByValue(const string& value) {
    Node* current = head;
    int index = 0;
    bool found = false;
    
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Element '" << value << "' found at position " << index << endl;
            found = true;
        }
        current = current->next;
        index++;
    }
    
    if (!found) {
        cout << "Element '" << value << "' not found in the list" << endl;
    }
}

// Чтение с начала - O(n)
void LinkedList::readFromHead() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* current = head;
    cout << "List (from head to tail): ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Рекурсивный вывод в обратном порядке - O(n)
void LinkedList::printReverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    printReverse(node->next);
    cout << node->data;
    if (node != head) {
        cout << " -> ";
    }
}

// Чтение с конца - O(n)
void LinkedList::readFromTail() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    cout << "List (from tail to head): ";
    printReverse(head);
    cout << endl;
}

// Чтение с индекса - O(n)
void LinkedList::readFromIndex(int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    int count = 0;
    Node* temp = current;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    
    string* arr = new string[count];
    temp = current;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    
    cout << "List from index " << index << " to head: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << arr[i];
        if (i > 0) {
            cout << " -> ";
        }
    }
    cout << endl;
    
    delete[] arr;
}