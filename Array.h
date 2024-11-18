#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Array {
private:
    int* data;       // Указатель на массив
    int size;        // Текущий размер массива
    int capacity;    // Максимальная вместимость массива

public:
    // Конструктор
    Array(int cap = 10);

    // Деструктор
    ~Array();

    // Инициализация массива
    void Ainit(int cap);

    // Уничтожение массива
    void Adestroy();

    // Добавление элемента в конец массива
    void Aappend(int value);

    // Вставка элемента на указанную позицию
    void Ainsert(int index, int value);

    // Получение элемента по индексу
    int Aget(int index) const;

    // Удаление элемента по индексу
    void Aremove(int index);

    // Замена элемента по индексу
    void Areplace(int index, int value);

    // Получение текущей длины массива
    int Alength() const;

    // Печать массива
    void printArray() const;

    // Запись массива в файл
    void writeToFileArray(const string& filename) const;
};

