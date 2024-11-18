#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>  // Для исключений

using namespace std;

class AVLNode {
public:
    int data;           // Значение узла
    AVLNode* left;      // Указатель на левое поддерево
    AVLNode* right;     // Указатель на правое поддерево
    int balance;        // Балансировка узла (разница в высотах поддеревьев)

    // Конструктор узла
    AVLNode(int val);
};

class AVLTree {
private:
    AVLNode* root;      // Корень дерева

    // Вспомогательные методы для работы с деревом
    int HeightAVL(AVLNode* node) const;                    // Вычисление высоты поддерева
    void SetBalanceAVL(AVLNode* node);                      // Установка баланса для узла
    void TurnRightAVL(AVLNode*& node);                      // Поворот вправо
    void TurnLeftAVL(AVLNode*& node);                       // Поворот влево
    void InsertAVL(AVLNode*& node, int key);                // Вставка элемента в дерево
    bool SearchAVL(AVLNode* node, int key) const;           // Поиск элемента в дереве
    AVLNode* MinValueAVLNode(AVLNode* node) const;          // Поиск минимального элемента в поддереве
    void DeleteAVLNode(AVLNode*& node, int key);            // Удаление узла из дерева
    void InOrderAVL(AVLNode* node) const;                   // Обход дерева в порядке InOrder
    void PrintTreeAVL(AVLNode* node, int space) const;      // Печать дерева
    void writeNodeToFile(AVLNode* node, ofstream& file, int depth) const; // Запись дерева в файл
    void clearAVL(AVLNode*& node);                          // Очистка дерева

public:
    AVLTree();  // Конструктор
    ~AVLTree(); // Деструктор

    // Основные методы работы с деревом
    void Insert(int key);                        // Вставка элемента в дерево
    bool Search(int key) const;                  // Поиск элемента в дереве
    void Delete(int key);                        // Удаление элемента из дерева
    void WriteToFile(const string& filename) const; // Запись дерева в файл
    int FindMin() const;                         // Поиск минимального элемента
    void PrintTree() const;                     // Печать дерева
    int Height() const;                          // Получение высоты дерева
    void Clear();                                // Очистка дерева
};
