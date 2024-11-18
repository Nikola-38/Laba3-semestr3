#include "LO.h"  // Include the header file

// Добавление элемента в голову списка
void LinkedList::addHead(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Добавление элемента в хвост списка
void LinkedList::addTail(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode; // Если список пуст, новый элемент становится головой
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Удаление элемента с головы списка
void LinkedList::deleteHead() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Удаление элемента с хвоста списка
void LinkedList::deleteTail() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Удаление элемента по значению
bool LinkedList::deleteByValue(int value) {
    if (!head) return false;

    // Если удаляется голова
    if (head->data == value) {
        deleteHead();
        return true;
    }

    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }
    return false;
}

// Поиск элемента по значению
LinkedList::Node* LinkedList::search(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Печать списка
void LinkedList::printList() const {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Освобождение памяти
void LinkedList::clearList() {
    while (head) {
        deleteHead();
    }
}

// Функция для записи списка в файл
void LinkedList::writeToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        file << temp->data << endl;
        temp = temp->next;
    }
    file.close();
}
