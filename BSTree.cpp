#include "header.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Конструктор - O(1)
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Деструктор - O(n)
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

// Рекурсивное удаление всех узлов дерева - O(n)
void BinarySearchTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Проверка на пустое дерево - O(1)
bool BinarySearchTree::isEmpty() {
    return root == nullptr;
}

// Вставка элемента - O(h), где h - высота дерева
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
}

// Рекурсивная вставка элемента - O(h)
TreeNode* BinarySearchTree::insertHelper(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    
    if (value < node->data) {
        node->left = insertHelper(node->left, value);
    } else if (value > node->data) {
        node->right = insertHelper(node->right, value);
    }
    // Если значение равно, не добавляем дубликат
    
    return node;
}

// Поиск элемента - O(h)
bool BinarySearchTree::search(int value) {
    return searchHelper(root, value) != nullptr;
}

// Рекурсивный поиск элемента - O(h)
TreeNode* BinarySearchTree::searchHelper(TreeNode* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }
    
    if (value < node->data) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

// Удаление элемента - O(h)
void BinarySearchTree::remove(int value) {
    root = removeHelper(root, value);
}

// Рекурсивное удаление элемента - O(h)
TreeNode* BinarySearchTree::removeHelper(TreeNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (value < node->data) {
        node->left = removeHelper(node->left, value);
    } else if (value > node->data) {
        node->right = removeHelper(node->right, value);
    } else {
        // Узел найден - начинаем удаление
        
        // Случай 1: Узел без детей или с одним ребенком - O(1)
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        
        // Случай 2: Узел с двумя детьми - O(h)
        // Находим минимальный элемент в правом поддереве
        TreeNode* temp = findMin(node->right);
        
        // Копируем данные минимального элемента
        node->data = temp->data;
        
        // Удаляем минимальный элемент
        node->right = removeHelper(node->right, temp->data);
    }
    
    return node;
}

// Поиск минимального элемента в поддереве - O(h)
TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Подсчет количества узлов в дереве - O(n)
int BinarySearchTree::countNodes(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Получение высоты дерева - O(n)
int BinarySearchTree::getTreeHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}

// Заполнение массива информацией о узлах дерева - O(n)
void BinarySearchTree::fillTreeInfo(TreeNode* node, TreeInfo* infoArray, int* index, int level, const char* branch) {
    if (node == nullptr) {
        return;
    }
    
    // Заполняем информацию о текущем узле
    int currentIndex = (*index)++;
    infoArray[currentIndex].level = level;
    infoArray[currentIndex].branch = branch;
    infoArray[currentIndex].value = node->data;
    
    // Информация о левом потомке
    if (node->left != nullptr) {
        infoArray[currentIndex].leftChild = node->left->data;
        infoArray[currentIndex].hasLeft = true;
    } else {
        infoArray[currentIndex].leftChild = 0;
        infoArray[currentIndex].hasLeft = false;
    }
    
    // Информация о правом потомке
    if (node->right != nullptr) {
        infoArray[currentIndex].rightChild = node->right->data;
        infoArray[currentIndex].hasRight = true;
    } else {
        infoArray[currentIndex].rightChild = 0;
        infoArray[currentIndex].hasRight = false;
    }
    
    // Рекурсивно обходим потомков
    fillTreeInfo(node->left, infoArray, index, level + 1, "Левая");
    fillTreeInfo(node->right, infoArray, index, level + 1, "Правая");
}

// Вывод дерева в виде таблицы - O(n)
void BinarySearchTree::print() {
    if (isEmpty()) {
        cout << "Дерево пустое" << endl;
        return;
    }
    
    int nodeCount = countNodes(root);
    TreeInfo* infoArray = new TreeInfo[nodeCount];
    int currentIndex = 0;
    
    fillTreeInfo(root, infoArray, &currentIndex, 0, "Корень");
    
    // Вывод заголовка
    cout << "\n";
    cout << "│ Уровень │  Ветвь  │ Значение  │  Левый потомок  │  Правый потомок  │" << endl;
    
    // Вывод данных
    for (int i = 0; i < nodeCount; i++) {
        cout << "│ " << "\t" << right << infoArray[i].level << " "
             << "│ " << "\t" << left << infoArray[i].branch << " "
             << "│ " << "\t" << right << infoArray[i].value << " ";
        
        // Левый потомок
        cout << "│ " << "\t" << right;
        if (infoArray[i].hasLeft) {
            cout << infoArray[i].leftChild;
        } else {
            cout << "нет";
        }
        cout << " ";
        
        // Правый потомок
        cout << "│ " << setw(16) << right;
        if (infoArray[i].hasRight) {
            cout << infoArray[i].rightChild;
        } else {
            cout << "нет";
        }
        cout << " │" << endl;
    }
    
    cout << "Высота дерева: " << getTreeHeight(root) << endl;
    cout << "Всего узлов: " << nodeCount << endl;
    
    // Освобождаем память
    delete[] infoArray;
}