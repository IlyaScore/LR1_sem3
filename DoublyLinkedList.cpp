#include "header.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Добавление в начало - O(1)
void DoublyLinkedList::pushHead(const string& value) {
    NodeDL* newNode = new NodeDL(value, head, nullptr);
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

// Добавление в конец - O(1)
void DoublyLinkedList::pushTail(const string& value) {
    NodeDL* newNode = new NodeDL(value, nullptr, tail);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

// Добавление после индекса - O(n)
void DoublyLinkedList::pushAfterIndex(int index, const string& value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    NodeDL* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    NodeDL* newNode = new NodeDL(value, current->next, current);
    
    if (current->next) {
        current->next->prev = newNode;
    } else {
        tail = newNode;
    }
    
    current->next = newNode;
    cout << "Element '" << value << "' added after index " << index << endl;
}

// Добавление перед индексом - O(n)
void DoublyLinkedList::pushBeforeIndex(int index, const string& value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    if (index == 0) {
        pushHead(value);
        return;
    }
    
    NodeDL* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    NodeDL* newNode = new NodeDL(value, current, current->prev);
    current->prev->next = newNode;
    current->prev = newNode;
    cout << "Element '" << value << "' added before index " << index << endl;
}

// Удаление из начала - O(1)
void DoublyLinkedList::popHead() {
    if (!head) return;
    NodeDL* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

// Удаление из конца - O(1)
void DoublyLinkedList::popTail() {
    if (!tail) return;
    NodeDL* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

// Удаление после индекса - O(n)
void DoublyLinkedList::popAfterIndex(int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    NodeDL* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr || current->next == nullptr) {
        cout << "Cannot remove element after index " << index << "!" << endl;
        return;
    }
    
    NodeDL* temp = current->next;
    current->next = temp->next;
    
    if (temp->next) {
        temp->next->prev = current;
    } else {
        tail = current;
    }
    
    delete temp;
    cout << "Element removed after index " << index << endl;
}

// Удаление перед индексом - O(n)
void DoublyLinkedList::popBeforeIndex(int index) {
    if (head == nullptr || index <= 0) {
        cout << "Cannot remove element before index " << index << "!" << endl;
        return;
    }
    
    if (index == 1) {
        popHead();
        return;
    }
    
    NodeDL* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr || current->prev == nullptr) {
        cout << "Cannot remove element before index " << index << "!" << endl;
        return;
    }
    
    NodeDL* temp = current->prev;
    temp->prev->next = current;
    current->prev = temp->prev;
    
    delete temp;
    cout << "Element removed before index " << index << endl;
}

// Удаление по значению - O(n)
void DoublyLinkedList::popByValue(const string& value) {
    NodeDL* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Поиск по значению - O(n)
bool DoublyLinkedList::search(const string& value) {
    NodeDL* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Чтение с начала - O(n)
void DoublyLinkedList::readFromHead() {
    NodeDL* current = head;
    cout << "List (from head to tail): ";
    while (current) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Чтение с конца - O(n)
void DoublyLinkedList::readFromTail() {
    NodeDL* current = tail;
    cout << "List (from tail to head): ";
    while (current) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << endl;
}

// Чтение с индекса - O(n)
void DoublyLinkedList::readFromIndex(int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    NodeDL* current = head;
    int currentIndex = 0;
    
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    
    if (current == nullptr) {
        cout << "Index " << index << " is out of list bounds!" << endl;
        return;
    }
    
    cout << "List from index " << index << " to head: ";
    NodeDL* temp = current;
    while (temp) {
        cout << temp->data;
        if (temp->prev != nullptr) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}