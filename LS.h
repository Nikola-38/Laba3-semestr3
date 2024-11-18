#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DoublyLinkedList {
private:
    // Структура для узлов списка
    struct NodeL {
        int data;            // Данные узла
        NodeL* next;         // Указатель на следующий узел
        NodeL* previous;     // Указатель на предыдущий узел
    };

    NodeL* head;  // Указатель на голову списка
    NodeL* tail;  // Указатель на хвост списка

public:
    // Конструктор
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор для очистки памяти
    ~DoublyLinkedList() {
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
    NodeL* search(int value);

    // Печать списка
    void printList() const;

    // Очистка списка
    void clearList();
    
    NodeL* getHead() const;
    NodeL* getTail() const;

    // Запись списка в файл
    void writeToFile(const string& filename) const;

    // Чтение списка из файла
    void readFromFile(const string& filename);
};


