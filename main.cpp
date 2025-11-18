#include "header.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

// Функция для сохранения очереди в файл
void saveQueueToFile(Queue& q) {
    ofstream file("txt/queue.txt");
    Node* current = q.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки очереди из файла
void loadQueueFromFile(Queue& q) {
    ifstream file("txt/queue.txt");
    string value;
    while (file >> value) {
        q.push(value);
    }
    file.close();
}

// Функция для сохранения стека в файл
void saveStackToFile(Stack& s) {
    ofstream file("txt/stack.txt");
    Node* current = s.top;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки стека из файла
void loadStackFromFile(Stack& s) {
    ifstream file("txt/stack.txt");
    string value;
    while (file >> value) {
        s.push(value);
    }
    file.close();
}

// Функция для сохранения односвязного списка в файл
void saveLinkedListToFile(LinkedList& list) {
    ofstream file("txt/singlylist.txt");
    Node* current = list.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки односвязного списка из файла
void loadLinkedListFromFile(LinkedList& list) {
    ifstream file("txt/singlylist.txt");
    string value;
    while (file >> value) {
        list.pushTail(value);
    }
    file.close();
}

// Функция для сохранения массива в файл
void saveArrayToFile(Array& arr) {
    ofstream file("txt/array.txt");
    for (int i = 0; i < arr.size; ++i) {
        file << arr.data[i] << endl;
    }
    file.close();
}

// Функция для загрузки массива из файла
void loadArrayFromFile(Array& arr) {
    ifstream file("txt/array.txt");
    string value;
    while (file >> value) {
        arr.pushEnd(value);
    }
    file.close();
}

// Функция для сохранения двусвязного списка в файл
void saveDoublyLinkedListToFile(DoublyLinkedList& list) {
    ofstream file("txt/doublelist.txt");
    NodeDL* current = list.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Функция для загрузки двусвязного списка из файла
void loadDoublyLinkedListFromFile(DoublyLinkedList& list) {
    ifstream file("txt/doublelist.txt");
    string value;
    while (file >> value) {
        list.pushTail(value);
    }
    file.close();
}

// Функция для рекурсивного сохранения дерева в файл
void saveTreeHelper(TreeNode* node, ofstream& file) {
    if (node == nullptr) {
        file << "NULL" << endl;
        return;
    }
    
    // Сохраняем значение текущего узла
    file << node->data << endl;
    
    // Рекурсивно сохраняем левое и правое поддеревья
    saveTreeHelper(node->left, file);
    saveTreeHelper(node->right, file);
}

// Функция для сохранения дерева в файл
void saveTreeToFile(BinarySearchTree& tree) {
    ofstream file("txt/tree.txt");
    
    saveTreeHelper(tree.root, file);
    file.close();

}

// Функция для рекурсивной загрузки дерева из файла
TreeNode* loadTreeHelper(ifstream& file) {
    string line;
    if (!getline(file, line) || line == "NULL") {
        return nullptr;
    }
    
    try {
        int value = stoi(line);
        TreeNode* node = new TreeNode(value);
        node->left = loadTreeHelper(file);
        node->right = loadTreeHelper(file);
        return node;
    } catch (const exception& e) {
        cerr << "Error reading tree data from file: " << e.what() << endl;
        return nullptr;
    }
}

// Функция для загрузки дерева из файла
void loadTreeFromFile(BinarySearchTree& tree) {
    ifstream file("txt/tree.txt");
    
    // Очищаем существующее дерево
    tree.~BinarySearchTree();
    tree.root = nullptr;
    
    tree.root = loadTreeHelper(file);
    file.close();
}

// Функция для вывода справки по командам
void printHelp() {
    cout << "================================ СПРАВКА ПО КОМАНДАМ ================================" << endl;
    cout << endl;
    cout << "ОЧЕРЕДЬ (Queue):" << endl;
    cout << "  QPUSH <value>    - Добавить элемент в очередь" << endl;
    cout << "  QPOP             - Удалить элемент из очереди" << endl;
    cout << "  QPRINT           - Вывести очередь" << endl;
    cout << "  QEXIT            - Выйти из режима очереди" << endl;
    cout << endl;
    cout << "СТЕК (Stack):" << endl;
    cout << "  SPUSH <value>    - Добавить элемент в стек" << endl;
    cout << "  SPOP             - Удалить элемент из стека" << endl;
    cout << "  SPRINT           - Вывести стек" << endl;
    cout << "  SEXIT            - Выйти из режима стека" << endl;
    cout << endl;
    cout << "ОДНОСВЯЗНЫЙ СПИСОК (Forward List):" << endl;
    cout << "  FPUSHH <value>   - Добавить элемент в начало" << endl;
    cout << "  FPUSHT <value>   - Добавить элемент в конец" << endl;
    cout << "  FPUSHAI <index> <value> - Добавить после индекса" << endl;
    cout << "  FPUSHBI <index> <value> - Добавить перед индексом" << endl;
    cout << "  FPOPH            - Удалить из начала" << endl;
    cout << "  FPOPT            - Удалить из конца" << endl;
    cout << "  FPOPAI <index>   - Удалить после индекса" << endl;
    cout << "  FPOPBI <index>   - Удалить перед индексом" << endl;
    cout << "  FPOPV <value>    - Удалить по значению" << endl;
    cout << "  FFIND <value>    - Найти по значению" << endl;
    cout << "  FPRINTFH         - Вывести с начала" << endl;
    cout << "  FPRINTFT         - Вывести с конца" << endl;
    cout << "  FPRINTFI <index> - Вывести с индекса" << endl;
    cout << "  FEXIT            - Выйти из режима списка" << endl;
    cout << endl;
    cout << "ДВУСВЯЗНЫЙ СПИСОК (Doubly Linked List):" << endl;
    cout << "  DPUSHH <value>   - Добавить элемент в начало" << endl;
    cout << "  DPUSHT <value>   - Добавить элемент в конец" << endl;
    cout << "  DPUSHAI <index> <value> - Добавить после индекса" << endl;
    cout << "  DPUSHBI <index> <value> - Добавить перед индексом" << endl;
    cout << "  DPOPH            - Удалить из начала" << endl;
    cout << "  DPOPT            - Удалить из конца" << endl;
    cout << "  DPOPAI <index>   - Удалить после индекса" << endl;
    cout << "  DPOPBI <index>   - Удалить перед индексом" << endl;
    cout << "  DPOPV <value>    - Удалить по значению" << endl;
    cout << "  DFIND <value>    - Найти по значению" << endl;
    cout << "  DPRINTFH         - Вывести с начала" << endl;
    cout << "  DPRINTFT         - Вывести с конца" << endl;
    cout << "  DPRINTFI <index> - Вывести с индекса" << endl;
    cout << "  DEXIT            - Выйти из режима двусвязного списка" << endl;
    cout << endl;
    cout << "МАССИВ (Array):" << endl;
    cout << "  MPUSH <index> <value> - Добавить элемент по индексу" << endl;
    cout << "  MPUSHH <value>   - Добавить элемент в конец" << endl;
    cout << "  MPOP <index>     - Удалить элемент по индексу" << endl;
    cout << "  MGET <index>     - Получить элемент по индексу" << endl;
    cout << "  MREPLACE <index> <value> - Заменить элемент по индексу" << endl;
    cout << "  MLENGTH          - Получить длину массива" << endl;
    cout << "  MPRINT           - Вывести массив" << endl;
    cout << "  MEXIT            - Выйти из режима массива" << endl;
    cout << endl;
    cout << "БИНАРНОЕ ДЕРЕВО ПОИСКА (Binary Search Tree):" << endl;
    cout << "  TINSERT <value>  - Вставить элемент" << endl;
    cout << "  TDEL <value>     - Удалить элемент" << endl;
    cout << "  TGET <value>     - Найти элемент" << endl;
    cout << "  TPRINT           - Вывести дерево" << endl;
    cout << "  TEXIT            - Выйти из режима дерева" << endl;
    cout << endl;
    cout << "ОБЩИЕ КОМАНДЫ:" << endl;
    cout << "  HELP             - Показать эту справку" << endl;
    cout << "  EXIT             - Выйти из программы (сохранить все данные)" << endl;
    cout << endl;
    cout << "====================================================================================" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание папки txt, если её нет
    fs::create_directory("txt");

    // Инициализация структур данных
    Queue q;
    Stack s;
    LinkedList list;
    Array arr;
    DoublyLinkedList dList;
    BinarySearchTree tree;

    // Загрузка данных из файлов
    loadQueueFromFile(q);
    loadStackFromFile(s);
    loadLinkedListFromFile(list);
    loadArrayFromFile(arr);
    loadDoublyLinkedListFromFile(dList);
    loadTreeFromFile(tree);

    string command;
    string input;
    string value;
    int treeVal;
    int index;
    int nodeCount;

    printHelp();

    while (true) {
        cout << "> ";
        getline(cin, input);
        
        // Создаем строковый поток для разбора ввода
        stringstream ss(input);
        ss >> command;

        // Работа с очередью
        if (command == "QPUSH") {
            if (ss >> value) {
                q.push(value);
            } else {
                cout << "Usage: QPUSH <value>" << endl;
            }
        } else if (command == "QPOP") {
            q.pop();
        } else if (command == "QPRINT") {
            q.read();
        } else if (command == "QEXIT") {
            saveQueueToFile(q);
            break;
        }

        // Работа со стеком
        else if (command == "SPUSH") {
            if (ss >> value) {
                s.push(value);
            } else {
                cout << "Usage: SPUSH <value>" << endl;
            }
        } else if (command == "SPOP") {
            s.pop();
        } else if (command == "SPRINT") {
            s.read();
        } else if (command == "SEXIT") {
            saveStackToFile(s);
            break;
        }

        // Работа с односвязным списком
        else if (command == "FPUSHH") {
            if (ss >> value) {
                list.pushHead(value);
            } else {
                cout << "Usage: FPUSHH <value>" << endl;
            }
        } else if (command == "FPUSHT") {
            if (ss >> value) {
                list.pushTail(value);
            } else {
                cout << "Usage: FPUSHT <value>" << endl;
            }
        } else if (command == "FPUSHAI") {
            if (ss >> index >> value) {
                list.pushAfterIndex(index, value);
            } else {
                cout << "Usage: FPUSHAI <index> <value>" << endl;
            }
        } else if (command == "FPUSHBI") {
            if (ss >> index >> value) {
                list.pushBeforeIndex(index, value);     
            } else {
                cout << "Usage: FPUSHBI <index> <value>" << endl;
            }
        } else if (command == "FPOPH") {
            list.popHead();
        } else if (command == "FPOPT") {
            list.popTail();
        } else if (command == "FPOPAI") {
            if (ss >> index) {
                list.popAfterIndex(index);
            } else {
                cout << "Usage: FPOPAI <index>" << endl;
            }
        } else if (command == "FPOPBI") {
            if (ss >> index) {
                list.popBeforeIndex(index);
            } else {
                cout << "Usage: FPOPBI <index>" << endl;
            }
        } else if (command == "FPOPV") {
            if (ss >> value) {
                list.popByValue(value);
            } else {
                cout << "Usage: FPOPV <value>" << endl;
            }
        } else if (command == "FFIND") {
            if (ss >> value) {
                list.findByValue(value);
            } else {
                cout << "Usage: FFIND <value>" << endl;
            }
        } else if (command == "FPRINTFH") {
            list.readFromHead();
        } else if (command == "FPRINTFT") {
            list.readFromTail();
        } else if (command == "FPRINTFI") {
            if (ss >> index) {
                list.readFromIndex(index);
            } else {
                cout << "Usage: FPRINTFI <index>" << endl;
            }
        } else if (command == "FEXIT") {
            saveLinkedListToFile(list);
            break;
        }

        // Работа с двусвязным списком
        else if (command == "DPUSHH") {
            if (ss >> value) {
                dList.pushHead(value);
            } else {
                cout << "Usage: DPUSHH <value>" << endl;
            }
        } else if (command == "DPUSHT") {
            if (ss >> value) {
                dList.pushTail(value);
            } else {
                cout << "Usage: DPUSHT <value>" << endl;
            }
        } else if (command == "DPUSHAI") {
            if (ss >> index >> value) {
                dList.pushAfterIndex(index, value);
            } else {
                cout << "Usage: DPUSHAI <index> <value>" << endl;
            }
        } else if (command == "DPUSHBI") {
            if (ss >> index >> value) {
                dList.pushBeforeIndex(index, value);
            } else {
                cout << "Usage: DPUSHBI <index> <value>" << endl;
            }
        } else if (command == "DPOPH") {
            dList.popHead();
        } else if (command == "DPOPT") {
            dList.popTail();
        } else if (command == "DPOPAI") {
            if (ss >> index) {
                dList.popAfterIndex(index);
            } else {
                cout << "Usage: DPOPAI <index>" << endl;
            }
        } else if (command == "DPOPBI") {
            if (ss >> index) {
                dList.popBeforeIndex(index);
            } else {
                cout << "Usage: DPOPBI <index>" << endl;
            }
        } else if (command == "DPOPV") {
            if (ss >> value) {
                dList.popByValue(value);
            } else {
                cout << "Usage: DPOPV <value>" << endl;
            }
        } else if (command == "DFIND") {
            if (ss >> value) {
                cout << (dList.search(value) ? "found" : "not found") << endl;
            } else {
                cout << "Usage: DFIND <value>" << endl;
            }
        } else if (command == "DPRINTFH") {
            dList.readFromHead();
        } else if (command == "DPRINTFT") {
            dList.readFromTail();
        } else if (command == "DPRINTFI") {
            if (ss >> index) {
                dList.readFromIndex(index);
            } else {
                cout << "Usage: DPRINTFI <index>" << endl;
            }
        } else if (command == "DEXIT") {
            saveDoublyLinkedListToFile(dList);
            break;
        }

        // Работа с массивом
        else if (command == "MPUSH") {
            if (ss >> index >> value) {
                arr.push(index, value);
            } else {
                cout << "Usage: MPUSH <index> <value>" << endl;
            }
        } else if (command == "MPUSHH") {
            if (ss >> value) {
                arr.pushEnd(value);
            } else {
                cout << "Usage: MPUSHH <value>" << endl;
            }
        } else if (command == "MPOP") {
            if (ss >> index) {
                arr.pop(index);
            } else {
                cout << "Usage: MPOP <index>" << endl;
            }
        } else if (command == "MGET") {
            if (ss >> index) {
                cout << "Element at position " << index << ": " << arr.get(index) << endl;
            } else {
                cout << "Usage: MGET <index>" << endl;
            }
        } else if (command == "MREPLACE") {
            if (ss >> index >> value) {
                arr.replace(index, value);
            } else {
                cout << "Usage: MREPLACE <index> <value>" << endl;
            }
        } else if (command == "MLENGTH") {
            cout << "Array length: " << arr.length() << endl;
        } else if (command == "MPRINT") {
            arr.read();
        } else if (command == "MEXIT") {
            saveArrayToFile(arr);
            arr.destroy();
            break;
        }

        // Работа с бинарным деревом поиска
        else if (command == "TINSERT") {
            if (ss >> treeVal) {
                tree.insert(treeVal);
            } else {
                cout << "Usage: TINSERT <value>" << endl;
            }
        } else if (command == "TDEL") {
            if (ss >> treeVal) {
                if (tree.search(treeVal)) {
                    tree.remove(treeVal);
                } else {
                    cout << "Element '" << treeVal << "' not found in tree" << endl;
                }
            } else {
                cout << "Usage: TDEL <value>" << endl;
            }
        } else if (command == "TGET") {
            if (ss >> treeVal) {
                if (tree.search(treeVal)) {
                    cout << "Element '" << treeVal << "' found in tree" << endl;
                } else {
                    cout << "Element '" << treeVal << "' not found in tree" << endl;
                }
            } else {
                cout << "Usage: TGET <value>" << endl;
            }
        } else if (command == "TPRINT") {
            tree.print();
        } else if (command == "TEXIT") {
            saveTreeToFile(tree);
            break;
        }
        
        // Вывод справки
        else if (command == "HELP") {
            printHelp();
        }
        
        // Выход из программы
        else if (command == "EXIT") {
            saveQueueToFile(q);
            saveStackToFile(s);
            saveLinkedListToFile(list);
            saveArrayToFile(arr);
            saveDoublyLinkedListToFile(dList);
            saveTreeToFile(tree); 
            break;
        } else {
            cout << "Unknown command. Type HELP for list of commands." << endl;
        }
    }

    return 0;
}