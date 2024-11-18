#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class HashTable {
private:
    static const int tableSize = 10; // Размер хеш-таблицы

    // Структура для хранения элементов хеш-таблицы
    struct NodeH {
        string key;
        string value;
        NodeH* next;
    };

    NodeH* table[tableSize]; // Массив для хранения элементов хеш-таблицы

public:
    // Конструктор
    HashTable();

    // Хеш-функция
    int hashFunction(const string& key);

    // Добавление элемента
    void insertH(const string& key, const string& value);

    // Получение значения по ключу
    string getH(const string& key);

    // Удаление элемента по ключу
    void removeH(const string& key);

    // Вывод всех элементов хеш-таблицы
    void printTableH();

    // Запись хеш-таблицы в файл
    void writeToFileH(const string& filename);

    // Чтение хеш-таблицы из файла
    void readFromFileH(const string& filename);

    // Освобождение памяти вручную
    void clearH();

    // Деструктор для очистки памяти
    ~HashTable();
};
