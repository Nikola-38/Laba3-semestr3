#include "Stack.h"
using namespace std;

    // Добавление элемента в стек (push)
    void Stack::push(const string& data) {
        NodeS* newNode = new NodeS{data, nullptr};
        newNode->next = head;
        head = newNode;
    }

    // Удаление элемента из стека (pop)
    string Stack::pop() {
        if (head == nullptr) {
            cout << "Стек пуст!" << endl;
            return ""; // Возвращаем пустую строку, если стек пуст
        }

        NodeS* temp = head;
        string data = temp->data; // Сохраняем данные удаляемого элемента
        head = head->next; // Обновляем вершину стека
        delete temp; // Освобождаем память
        return data; // Возвращаем данные удаленного элемента
    }

    // Функция для вывода всех элементов стека
    void Stack::print() const {
        if (head == nullptr) {
            cout << "Стек пуст!" << endl;
            return;
        }

        NodeS* current = head;
        // Вывод элементов стека от вершины к основанию
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Освобождение памяти стека
    void Stack::clearStack() {
        while (head) {
            pop();
        }
    }

    // Функция для записи стека в файл
    void Stack::writeToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Не удалось открыть файл для записи.\n";
            return;
        }
        NodeS* temp = head;
        while (temp) {
            file << temp->data << endl;
            temp = temp->next;
        }
        file.close();
    }


