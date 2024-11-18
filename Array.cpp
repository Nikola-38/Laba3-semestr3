#include "Array.h"

// Конструктор
Array::Array(int cap) : size(0), capacity(cap) {
    data = new int[capacity];
}

// Деструктор
Array::~Array() {
    delete[] data;
}

// Инициализация массива
void Array::Ainit(int cap) {
    capacity = cap;
    size = 0;
    delete[] data;  // Освобождаем память, если она была выделена ранее
    data = new int[capacity];
}

// Уничтожение массива
void Array::Adestroy() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Добавление элемента в конец массива
void Array::Aappend(int value) {
    if (size >= capacity) {
        // Если массив переполнен, увеличиваем его размер
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}

// Вставка элемента на указанную позицию
void Array::Ainsert(int index, int value) {
    if (index < 0 || index > size) {
        cerr << "Index out of bounds.\n";
        return;
    }
    if (size >= capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < index; ++i) {
            newData[i] = data[i];
        }
        newData[index] = value;
        for (int i = index; i < size; ++i) {
            newData[i + 1] = data[i];
        }
        delete[] data;
        data = newData;
    } else {
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }
    ++size;
}

// Получение элемента по индексу
int Array::Aget(int index) const {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds.\n";
        return -1; // Возвращаем ошибочный индекс
    }
    return data[index];
}

// Удаление элемента по индексу
void Array::Aremove(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds.\n";
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// Замена элемента по индексу
void Array::Areplace(int index, int value) {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds.\n";
        return;
    }
    data[index] = value;
}

// Получение текущей длины массива
int Array::Alength() const {
    return size;
}

// Печать массива
void Array::printArray() const {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Запись массива в файл
void Array::writeToFileArray(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file << data[i] << " ";
        }
        file.close();
    } else {
        cerr << "Error opening file for writing.\n";
    }
}
