#include <iostream>
#include <fstream>
#include <iomanip>
#include "Array.h"
#include "AVL.h"
#include "Hash.h"
#include "LO.h"
#include "LS.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

void handleArrayCommands(Array& arr) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        // Приводим команду к нижнему регистру
        for (auto& c : command) c = tolower(c);

        if (command == "append") {
            int value;
            cin >> value;

            // Проверяем, существует ли уже такой элемент в массиве
            bool exists = false;
            for (int i = 0; i < arr.Alength(); ++i) {  // Используем Alength()
                if (arr.Aget(i) == value) {  // Используем Aget()
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                arr.Aappend(value);  // Используем Aappend()
                arr.writeToFileArray("ARRAY.txt");  // Используем writeToFileArray()
            } else {
                cout << "Значение уже существует." << endl;
            }
        }
        else if (command == "ainsert") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index <= arr.Alength()) {  // Используем Alength()
                arr.Ainsert(index, value);  // Используем Ainsert()
                arr.writeToFileArray("ARRAY.txt");  // Используем writeToFileArray()
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "aget") {
            int index;
            cin >> index;
            if (index >= 0 && index < arr.Alength()) {  // Используем Alength()
                cout << "Элемент по индексу " << index << ": " << arr.Aget(index) << endl;  // Используем Aget()
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "aremov") {
            int index;
            cin >> index;
            if (index >= 0 && index < arr.Alength()) {  // Используем Alength()
                arr.Aremove(index);  // Используем Aremove()
                arr.writeToFileArray("ARRAY.txt");  // Используем writeToFileArray()
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "areplace") {
            int index, value;
            cin >> index >> value;
            if (index >= 0 && index < arr.Alength()) {  // Используем Alength()
                arr.Areplace(index, value);  // Используем Areplace()
                arr.writeToFileArray("ARRAY.txt");  // Используем writeToFileArray()
            } else {
                cout << "Индекс вне диапазона." << endl;
            }
        }
        else if (command == "asize") {
            cout << "Длина массива: " << arr.Alength() << endl;  // Используем Alength()
        }
        else if (command == "print") {
            arr.printArray();  // Используем printArray()
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Неизвестная команда." << endl;
        }
    }
}


void handleAVLCommands(AVLTree& tree) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "AVLINSERT") {
            int value;
            cin >> value;
            tree.Insert(value); // Вставка через метод класса AVLTree
            tree.WriteToFile("AVL.txt"); // Запись в файл через метод класса
        }
        else if (command == "AVLDEL") {
            int value;
            cin >> value;
            tree.Delete(value); // Удаление через метод класса AVLTree
            tree.WriteToFile("AVL.txt"); // Запись в файл через метод класса
        }
        else if (command == "AVLSEARCH") {
            int value;
            cin >> value;
            if (tree.Search(value)) { // Поиск через метод класса AVLTree
                cout << "Значение " << value << " найдено." << endl;
            }
            else {
                cout << "Значение " << value << " не найдено." << endl;
            }
        }
        else if (command == "AVLHEIGHT") {
            // Получение высоты дерева
            cout << "Высота дерева: " << tree.Height() << endl;
        }
        else if (command == "AVLMIN") {
            // Проверка на пустоту дерева перед поиском минимального элемента
            if (tree.Height() == 0) {
                cout << "Дерево пусто, минимальный элемент не существует." << endl;
            } else {
                int minElement = tree.FindMin();
                cout << "Минимальный элемент: " << minElement << endl;
            }
        }
        else if (command == "PRINT") {
            cout << "Дерево:" << endl;
            tree.PrintTree(); // Вывод дерева через метод класса
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}


void handleHashCommands(HashTable& hashTable) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "INSERTH") {
            string key, value;
            cin >> key >> value;
            hashTable.insertH(key, value);  // Вставка элемента
            hashTable.writeToFileH("HASH.txt");  // Запись хеш-таблицы в файл
        }
        else if (command == "DELETEH") {
            string key;
            cin >> key;
            hashTable.removeH(key);  // Удаление элемента по ключу
            hashTable.writeToFileH("HASH.txt");  // Запись в файл после удаления
        }
        else if (command == "SEARCHH") {
            string key;
            cin >> key;
            string value = hashTable.getH(key);  // Поиск по ключу
            if (value != "Ключ не найден") {
                cout << "Найдено: " << key << " -> " << value << endl;
            } else {
                cout << "Ключ не найден." << endl;
            }
        }
        else if (command == "PRINTH") {
            cout << "Содержимое хеш-таблицы: " << endl;
            hashTable.printTableH();  // Вывод хеш-таблицы
        }
        else if (command == "EXIT") {
            break;  // Выход из цикла
        }
        else {
            cout << "Неизвестная команда." << endl;
        }
    }
}



void handleListONECommands(LinkedList& list, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LOADDHEAD") {
            int value;
            cin >> value;
            list.addHead(value);
            list.writeToFile(filename);
        }
        else if (command == "LOADDTAIL") {
            int value;
            cin >> value;
            list.addTail(value);
            list.writeToFile(filename);
        }
        else if (command == "LODELHEAD") {
            if (list.search(0)) {  // Если список не пуст, мы можем удалить голову
                list.deleteHead();
                list.writeToFile(filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELTAIL") {
            if (list.search(0)) {  // Если список не пуст
                list.deleteTail();
                list.writeToFile(filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LODELVAL") {
            int value;
            cin >> value;
            if (list.deleteByValue(value)) {
                list.writeToFile(filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOSEARCH") {
            int value;
            cin >> value;
            if (list.search(value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LOPRINT") {
            cout << "Список: ";
            list.printList();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleListSECCommands(DoublyLinkedList& list, const string& filename) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "LSADDHEAD") {
            int value;
            cin >> value;
            list.addHead(value);
            list.writeToFile(filename);
        }
        else if (command == "LSADDTAIL") {
            int value;
            cin >> value;
            list.addTail(value);
            list.writeToFile(filename);
        }
        else if (command == "LSDELHEAD") {
            if (list.getHead()) {
                list.deleteHead();
                list.writeToFile(filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LSDELTAIL") {
            if (list.getTail()) {
                list.deleteTail();
                list.writeToFile(filename);
            }
            else {
                cout << "Список пуст." << endl;
            }
        }
        else if (command == "LSDELVAL") {
            int value;
            cin >> value;
            if (list.deleteByValue(value)) {
                list.writeToFile(filename);
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LSSEARCH") {
            int value;
            cin >> value;
            if (list.search(value)) {
                cout << "Значение найдено." << endl;
            }
            else {
                cout << "Значение не найдено." << endl;
            }
        }
        else if (command == "LSPRINT") {
            cout << "Список: ";
            list.printList();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

void handleStackCommands(Stack& stack) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "SPUSH") {
            string value;
            cin >> value;
            stack.push(value);            // Используем метод push класса Stack
            stack.writeToFile("STACK.txt"); // Записываем в файл
        }
        else if (command == "SPOP") {
            string value = stack.pop();      // Используем метод pop класса Stack
            if (!value.empty()) {
                stack.writeToFile("STACK.txt"); // Записываем в файл
            }
            else {
                cout << "Стек пуст." << endl;
            }
        }
        else if (command == "SPRINT") {
            cout << "Стек: ";
            stack.print();   // Используем метод print класса Stack
        }
        else if (command == "EXIT") {
            break;  // Завершаем программу
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
}

// Функция для обработки команд с очередью
void handleQueueCommands(Queue& queue) {
    string command;
    while (true) {
        cout << ">> ";
        cin >> command;

        if (command == "QPUSH") {
            int value;
            cin >> value;
            queue.push(value); // Добавляем элемент в очередь
            queue.writeToFile("QUEUE.txt"); // Записываем состояние очереди в файл
        }
        else if (command == "QPOP") {
            int value = queue.pop(); // Удаляем элемент из очереди
            if (value != -1) {
                queue.writeToFile("QUEUE.txt"); // Записываем новое состояние очереди в файл
            }
            else {
                cout << "Очередь пуста." << endl;
            }
        }
        else if (command == "QPRINT") {
            cout << "Очередь: ";
            queue.print(); // Выводим все элементы очереди
        }
        else if (command == "EXIT") {
            break; // Выход из цикла
        }
        else {
            cout << "Неизвестная команда.\n"; // Обработка неизвестных команд
        }
    }
}

int main() {

    Array arr; // Using Array structure instead of pointer
    arr.Ainit(10); // Initialize array with initial capacity of 10
    AVLTree avlTree;  // Changed from pointer to object
    HashTable hashTable;
    LinkedList list;  // Changed from pointer to object
    DoublyLinkedList lsList; // Changed from pointer to object
    Queue queue;
    Stack stack;

    while (true) {
        string command;
        cout << ">> ";
        cin >> command;

        if (command == "ARRAY") {
            handleArrayCommands(arr); // Pass the array by reference
        }
        else if (command == "AVL") {
            handleAVLCommands(avlTree); // Pass the AVLTree by reference
        }
        else if (command == "HASH") {
            handleHashCommands(hashTable);
        }
        else if (command == "LO") {
            handleListONECommands(list, "LISTONE.txt");
        }
        else if (command == "LS") {
            handleListSECCommands(lsList, "LISTSEC.txt");
        }
        else if (command == "QUEUE") {
            handleQueueCommands(queue);
        }
        else if (command == "STACK") {
            handleStackCommands(stack);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "Неизвестная команда. Попробуйте снова." << endl;
        }
    }

    // Очистка памяти
    arr.Adestroy(); // Освобождаем память массива, если необходимо
    avlTree.Clear(); // Очистка дерева AVL, если есть такой метод в классе
    hashTable.clearH(); // Очистка хеш-таблицы, если есть такой метод
    list.clearList(); // Очистка списка (если используется объект LinkedList)
    lsList.clearList(); // Очистка двусвязного списка
    queue.clearQueue(); // Очистка очереди
    stack.clearStack(); // Очистка стека

    return 0;
}
