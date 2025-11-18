#include "header.h"
#include <iostream>

Array::Array() {
    capacity = 10;
    data = new string[capacity];
    size = 0;
}

// Вставка по индексу - O(n) из-за сдвига элементов
void Array::push(int index, const string& value) {
    if (index < 0 || index > size) {
        cout << "Error: invalid index" << endl;
        return;
    }
    
    // Увеличиваем вместимость при необходимости +
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        string* newData = new string[newCapacity];
        
        // Копируем существующие элементы
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    // Сдвигаем элементы вправо для освобождения места 
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
    size++;
}

// Добавление в конец - O(1) 
void Array::pushEnd(const string& value) {
    // Увеличиваем вместимость при необходимости 
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        string* newData = new string[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    data[size] = value;
    size++;
}

// Получение элемента по индексу - O(1)
string Array::get(int index) {
    if (index < 0 || index >= size) {
        return "Error: index out of bounds";
    }
    return data[index];
}

// Удаление по индексу - O(n) из-за сдвига элементов
void Array::pop(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: index out of bounds" << endl;
        return;
    }
    
    // Сдвигаем элементы влево для заполнения пустоты 
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    
    size--;
}

// Замена элемента - O(1)
void Array::replace(int index, const string& value) {
    if (index < 0 || index >= size) {
        cout << "Error: index out of bounds" << endl;
        return;
    }
    data[index] = value;
}

// Получение размера - O(1)
int Array::length() {
    return size;
}

// Вывод массива - O(n)
void Array::read() {
    cout << "Array [" << size << "/" << capacity << "]: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Уничтожение массива - O(1)
void Array::destroy() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    size = 0;
}