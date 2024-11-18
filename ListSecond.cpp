#include "LS.h"

using namespace std;

// Добавление элемента в голову списка
void DoublyLinkedList::addHead(int value) {
    NodeL* newNode = new NodeL{value, head, nullptr};
    if (head) {
        head->previous = newNode;
    } else {
        tail = newNode; // Если список был пуст, новый узел становится хвостом
    }
    head = newNode;
}

// Добавление элемента в хвост списка
void DoublyLinkedList::addTail(int value) {
    NodeL* newNode = new NodeL{value, nullptr, tail};
    if (!head) {
        head = newNode;
        tail = newNode; // Если список пуст, новый узел становится и головой, и хвостом
    } else {
        tail->next = newNode;
        tail = newNode; // Обновляем хвост
    }
}

// Удаление элемента с головы списка
void DoublyLinkedList::deleteHead() {
    if (!head) return;  // Если список пуст, нечего удалять
    NodeL* temp = head;
    head = head->next;
    if (head) {
        head->previous = nullptr;
    } else {
        tail = nullptr; // Если список стал пустым, обнуляем хвост
    }
    delete temp;
}

// Удаление элемента с хвоста списка
void DoublyLinkedList::deleteTail() {
    if (!tail) return;  // Если список пуст, нечего удалять
    if (head == tail) {
        delete head; // Если в списке только один элемент
        head = nullptr;
        tail = nullptr;
        return;
    }
    NodeL* temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
}

// Удаление элемента по значению
bool DoublyLinkedList::deleteByValue(int value) {
    if (!head) return false; // Если список пуст

    // Если удаляется голова
    if (head->data == value) {
        deleteHead();
        return true;
    }

    NodeL* current = head;
    while (current && current->data != value) {
        current = current->next;
    }

    if (current) {
        if (current->next) {
            current->next->previous = current->previous;
        } else {
            tail = current->previous; // Обновляем хвост, если удаляем последний элемент
        }
        if (current->previous) {
            current->previous->next = current->next;
        }
        delete current;
        return true;
    }

    return false; // Элемент не найден
}

// Поиск элемента по значению
DoublyLinkedList::NodeL* DoublyLinkedList::search(int value) {
    NodeL* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Если элемент не найден
}

// Печать списка
void DoublyLinkedList::printList() const {
    NodeL* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Очистка списка
void DoublyLinkedList::clearList() {
    while (head) {
        deleteHead();
    }
}

// Получение головы списка
DoublyLinkedList::NodeL* DoublyLinkedList::getHead() const {
    return head;
}

// Получение хвоста списка
DoublyLinkedList::NodeL* DoublyLinkedList::getTail() const {
    return tail;
}

// Запись списка в файл
void DoublyLinkedList::writeToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    NodeL* temp = head;
    while (temp) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
}

// Чтение списка из файла
void DoublyLinkedList::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл для чтения.\n";
        return;
    }

    clearList(); // Очищаем список перед загрузкой новых данных

    int value;
    int count = 0;
    while (file >> value) {
        addTail(value);
        count++;
    }
    if (count > 0) {
        cout << count << " элементов загружено из файла.\n";
    } else {
        cout << "Файл пуст или данные неверны.\n";
    }
    file.close();
}
