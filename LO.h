#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinkedList {
private:
    // Структура для узлов списка
    struct Node {
        int data;        // Данные узла
        Node* next;      // Указатель на следующий узел
    };

    Node* head;  // Указатель на голову списка

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор для очистки памяти
    ~LinkedList() {
        clearList();
    }
    // Добавление элемента в голову списка
    void addHead(int value);

    // Добавление элемента в хвост списка
    void addTail(int value);

    // Удаление элемента с головы списка
    void deleteHead();

    // Удаление элемента с хвоста списка
    void deleteTail();

    // Удаление элемента по значению
    bool deleteByValue(int value);

    // Поиск элемента по значению
    Node* search(int value);

    // Печать списка
    void printList() const;

    // Освобождение памяти
    void clearList();

    // Запись списка в файл
    void writeToFile(const string& filename) const;
};
