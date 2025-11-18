#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Структура узла для списка, очереди, стека
struct Node {
    string data;
    Node* next;
    Node(const string& value) : data(value), next(nullptr) {}
};

// Очередь
struct Queue {
    Node* head;
    Node* tail;
    Queue();
    void push(const string& value);
    void pop();
    void read();
};

// Стек
struct Stack {
    Node* top;
    Stack();
    void push(const string& value);
    string pop();
    void read();
};

// Односвязный список
struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList();
    ~LinkedList();
    void destroy();
    void pushHead(const string& value);
    void pushTail(const string& value);
    void pushAfterIndex(int index, const string& value);
    void pushBeforeIndex(int index, const string& value);
    void popHead();
    void popTail();
    void popAfterIndex(int index);
    void popBeforeIndex(int index);
    void popByValue(const string& value);
    void findByValue(const string& value);
    void readFromHead();
    void printReverse(Node* node);
    void readFromTail();
    void readFromIndex(int index);
};

// Двусвязный список
struct NodeDL {
    string data;
    NodeDL* next;
    NodeDL* prev;
    NodeDL(const string& value, NodeDL* nextNode = nullptr, NodeDL* prevNode = nullptr) : data(value), next(nextNode), prev(prevNode) {}
};

struct DoublyLinkedList {
    NodeDL* head;
    NodeDL* tail;
    DoublyLinkedList();
    void pushHead(const string& value);
    void pushTail(const string& value);
    void pushAfterIndex(int index, const string& value);  
    void pushBeforeIndex(int index, const string& value); 
    void popHead();
    void popTail();
    void popAfterIndex(int index);  
    void popBeforeIndex(int index); 
    void popByValue(const string& value);
    bool search(const string& value);
    void readFromHead();  
    void readFromTail(); 
    void readFromIndex(int index); 
};

// Узел бинарного дерева
struct TreeNode {
    int data;       // Данные узла 
    TreeNode* left;    // Левый потомок
    TreeNode* right;   // Правый потомок
    TreeNode(const int& val) : data(val), left(nullptr), right(nullptr) {}
};

// Структура для хранения данных о узлах при обходе
struct TreeInfo {
    int level;
    const char* branch;
    int value;
    int leftChild;
    int rightChild;
    bool hasLeft;
    bool hasRight;
};

// Структура для бинарного дерева поиска
struct BinarySearchTree {
    TreeNode* root;
    BinarySearchTree();
    ~BinarySearchTree();
    void destroyTree(TreeNode* node);
    bool isEmpty();
    void insert(int value);
    TreeNode* insertHelper(TreeNode* node, int value);
    bool search(int value);
    TreeNode* searchHelper(TreeNode* node, int value);
    void remove(int value);
    TreeNode* removeHelper(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node);
    void print();
    int countNodes(TreeNode* node);
    void fillTreeInfo(TreeNode* node, TreeInfo* infoArray, int* index, int level, const char* branch);
    int getTreeHeight(TreeNode* node);
};

// Структура массива для работы со строками
struct Array {
    string* data;       // Указатель на массив строк
    int capacity;       // Вместимость массива
    int size;           // Текущее количество элементов
    Array();
    void push(int index, const string& value);
    void pushEnd(const string& value);
    string get(int index);
    void pop(int index);
    void replace(int index, const string& value);
    int length();
    void read();
    void destroy();
};