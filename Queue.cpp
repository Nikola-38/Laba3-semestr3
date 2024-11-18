#include "Queue.h"
using namespace std;



    // Добавление элемента в очередь (push)
    void Queue::push(int value) {
        NodeQ* newNodeQ = new NodeQ;
        newNodeQ->data = value;
        newNodeQ->next = nullptr;

        if (!tail) { // Если очередь пуста
            head = newNodeQ;
            tail = newNodeQ;
        } else {
            tail->next = newNodeQ; // Добавляем новый узел в конец
            tail = newNodeQ; // Обновляем указатель на хвост
        }
    }

    // Удаление элемента из очереди (pop)
    int Queue::pop() {
        if (!head) {
            cout << "Очередь пуста!" << endl;
            return -1; // Возвращаем -1, если очередь пуста
        }

        NodeQ* temp = head;
        int value = temp->data;
        head = head->next; // Убираем элемент с головы

        if (!head) { // Если очередь стала пустой
            tail = nullptr;
        }

        delete temp; // Освобождаем память
        return value; // Возвращаем значение удаленного элемента
    }

    // Чтение (вывод всех элементов очереди)
    void Queue::print() const {
        NodeQ* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Освобождение памяти
    void Queue::clearQueue() {
        while (head) {
            pop();
        }
    }

    // Функция для записи очереди в файл
    void Queue::writeToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Не удалось открыть файл для записи.\n";
            return;
        }
        NodeQ* temp = head;
        while (temp) {
            file << temp->data << endl;
            temp = temp->next;
        }
        file.close();
    }

    // Функция для чтения очереди из файла
    void Queue::readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Не удалось открыть файл для чтения.\n";
            return;
        }

        clearQueue(); // Очищаем очередь перед загрузкой новых данных

        int value;
        int count = 0;  // Счетчик прочитанных значений
        while (file >> value) {
            push(value); // Используем push для добавления значений
            count++;
        }
        if (count > 0) {
            cout << count << " элементов загружено из файла.\n";
        } else {
            cout << "Файл пуст или данные неверны.\n";
        }
        file.close();
    }


