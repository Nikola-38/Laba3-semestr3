#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Queue {
private:
    // Структура для узлов очереди
    struct NodeQ {
        int data;         // Данные узла
        NodeQ* next;      // Указатель на следующий узел
    };

    NodeQ* head;   // Указатель на голову очереди
    NodeQ* tail;   // Указатель на хвост очереди

public:
    // Конструктор
    Queue() : head(nullptr), tail(nullptr) {}

    // Деструктор для очистки очереди
    ~Queue() {
        clearQueue();
    }

    // Добавление элемента в очередь (push)
    void push(int value);

    // Удаление элемента из очереди (pop)
    int pop();

    // Чтение (вывод всех элементов очереди)
    void print() const;

    // Освобождение памяти
    void clearQueue();

    // Запись очереди в файл
    void writeToFile(const string& filename) const;

    // Чтение очереди из файла
    void readFromFile(const string& filename);
};


