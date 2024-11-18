#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack {
private:
    // Структура для узлов стека
    struct NodeS {
        string data;      // Данные узла
        NodeS* next;      // Указатель на следующий узел
    };

    NodeS* head;   // Указатель на вершину стека

public:
    // Конструктор
    Stack() : head(nullptr) {}

    // Деструктор
    ~Stack() {
        clearStack();
    }

    // Добавление элемента в стек (push)
    void push(const string& data);

    // Удаление элемента из стека (pop)
    string pop();

    // Функция для вывода всех элементов стека
    void print() const;

    // Освобождение памяти стека
    void clearStack();

    // Функция для записи стека в файл
    void writeToFile(const string& filename) const;
};

