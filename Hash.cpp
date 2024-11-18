#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Hash.h"

using namespace std;



HashTable::HashTable() {
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr; // Инициализация массива нулями
    }
}

int HashTable::hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % tableSize; // Используем 31 как множитель
    }
    return hash;
}

void HashTable::insertH(const string& key, const string& value) {
    int index = hashFunction(key);
    NodeH* newNodeH = new NodeH{key, value, nullptr};

    if (!table[index]) {
        table[index] = newNodeH;
    } else {
        NodeH* current = table[index];
        while (current) {
            if (current->key == key) {
                current->value = value;
                delete newNodeH;
                return;
            }
            if (!current->next) {
                current->next = newNodeH;
                return;
            }
            current = current->next;
        }
    }
}

string HashTable::getH(const string& key) {
    int index = hashFunction(key);
    NodeH* current = table[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return "Ключ не найден";
}

void HashTable::removeH(const string& key) {
    int index = hashFunction(key);
    NodeH* current = table[index];
    NodeH* previous = nullptr;

    while (current) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Ключ не найден для удаления" << endl;
}

void HashTable::printTableH() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i]) {
            NodeH* current = table[i];
            while (current) {
                cout << "{" << current->key << ": " << current->value << "} ";
                current = current->next;
            }
            cout << endl;
        }
    }
}

void HashTable::writeToFileH(const string& filename) {
    ofstream outFile(filename, ios::trunc);
    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    for (int i = 0; i < tableSize; ++i) {
        NodeH* current = table[i];
        while (current) {
            outFile << current->key << "\t" << current->value << endl;
            current = current->next;
        }
    }
    outFile.close();
}

void HashTable::readFromFileH(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    clearH(); // Очищаем таблицу перед загрузкой новых данных

    string key, value;
    while (file >> key >> value) {
        insertH(key, value);
    }

    file.close();
}

void HashTable::clearH() {
    for (int i = 0; i < tableSize; i++) {
        NodeH* current = table[i];
        while (current) {
            NodeH* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    clearH();
}
