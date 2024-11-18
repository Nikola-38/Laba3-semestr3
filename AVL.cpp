#include <iostream>
#include <fstream>
#include "AVL.h"  // Подключаем заголовочный файл с классами

using namespace std;

// Конструктор для класса AVLNode
AVLNode::AVLNode(int val) : data(val), left(nullptr), right(nullptr), balance(0) {}

// Конструктор по умолчанию для класса AVLTree
AVLTree::AVLTree() : root(nullptr) {}

// Деструктор для класса AVLTree
AVLTree::~AVLTree() {
    clearAVL(root);  // Очистить дерево, начиная с корня
}

// Метод Clear() для класса AVLTree
void AVLTree::Clear() {
    clearAVL(root);  // Очистить дерево, начиная с корня
    root = nullptr;  // Убедиться, что корень теперь указывает на null
}

// Вычисление высоты поддерева
int AVLTree::HeightAVL(AVLNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    return max(HeightAVL(node->left), HeightAVL(node->right)) + 1;
}

// Установка баланса для узла
void AVLTree::SetBalanceAVL(AVLNode* node) {
    if (node != nullptr) {
        node->balance = HeightAVL(node->left) - HeightAVL(node->right);
    }
}

// Поворот вправо
void AVLTree::TurnRightAVL(AVLNode*& node) {
    AVLNode* leftSubtree = node->left;
    AVLNode* leftSubtreeRightSubtree = leftSubtree->right;

    leftSubtree->right = node;
    node->left = leftSubtreeRightSubtree;

    SetBalanceAVL(node);
    SetBalanceAVL(leftSubtree);

    node = leftSubtree; // Новый корень
}

// Поворот влево
void AVLTree::TurnLeftAVL(AVLNode*& node) {
    AVLNode* rightSubtree = node->right;
    AVLNode* rightSubtreeLeftSubtree = rightSubtree->left;

    rightSubtree->left = node;
    node->right = rightSubtreeLeftSubtree;

    SetBalanceAVL(node);
    SetBalanceAVL(rightSubtree);

    node = rightSubtree; // Новый корень
}

// Вставка элемента в дерево
void AVLTree::InsertAVL(AVLNode*& node, int key) {
    if (node == nullptr) {
        node = new AVLNode(key);
        return;
    }

    if (key < node->data) {
        InsertAVL(node->left, key);
    } else if (key > node->data) {
        InsertAVL(node->right, key);
    } else {
        return; // Дубликаты не допускаются
    }

    SetBalanceAVL(node);

    // Балансировка
    if (node->balance > 1) { // Левое поддерево тяжелее
        if (key < node->left->data) {
            TurnRightAVL(node); // LL
        } else {
            TurnLeftAVL(node->left); // LR
            TurnRightAVL(node);
        }
    }

    if (node->balance < -1) { // Правое поддерево тяжелее
        if (key > node->right->data) {
            TurnLeftAVL(node); // RR
        } else {
            TurnRightAVL(node->right); // RL
            TurnLeftAVL(node);
        }
    }
}

// Поиск минимального элемента в поддереве
AVLNode* AVLTree::MinValueAVLNode(AVLNode* node) const {
    AVLNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Поиск элемента в дереве
bool AVLTree::SearchAVL(AVLNode* node, int key) const {
    while (node) {
        if (key == node->data) {
            return true;
        } else if (key < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

// Удаление узла из дерева
void AVLTree::DeleteAVLNode(AVLNode*& node, int key) {
    if (!node) return;

    if (key < node->data) {
        DeleteAVLNode(node->left, key);
    } else if (key > node->data) {
        DeleteAVLNode(node->right, key);
    } else {
        // Удаление узла
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AVLNode* temp = MinValueAVLNode(node->right);
            node->data = temp->data;
            DeleteAVLNode(node->right, temp->data);
        }
    }

    if (!node) return;

    SetBalanceAVL(node);

    // Балансировка
    if (node->balance > 1) { // Левое поддерево тяжелее
        if (node->left->balance >= 0) {
            TurnRightAVL(node); // LL
        } else {
            TurnLeftAVL(node->left); // LR
            TurnRightAVL(node);
        }
    }

    if (node->balance < -1) { // Правое поддерево тяжелее
        if (node->right->balance <= 0) {
            TurnLeftAVL(node); // RR
        } else {
            TurnRightAVL(node->right); // RL
            TurnLeftAVL(node);
        }
    }
}

// Обход дерева в порядке InOrder
void AVLTree::InOrderAVL(AVLNode* node) const {
    if (node) {
        InOrderAVL(node->left);
        cout << node->data << " ";
        InOrderAVL(node->right);
    }
}

// Печать дерева в виде структуры
void AVLTree::PrintTreeAVL(AVLNode* node, int space) const {
    if (node == nullptr) return;

    space += 10;

    PrintTreeAVL(node->right, space);

    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << node->data << "\n";

    PrintTreeAVL(node->left, space);
}

// Запись дерева в файл
void AVLTree::writeNodeToFile(AVLNode* node, ofstream& file, int depth) const {
    if (!node) return;

    writeNodeToFile(node->right, file, depth + 1);

    for (int i = 0; i < depth; i++) {
        file << "    ";
    }
    file << node->data << endl;

    writeNodeToFile(node->left, file, depth + 1);
}

// Очистка дерева
void AVLTree::clearAVL(AVLNode*& node) {
    if (node) {
        clearAVL(node->left);
        clearAVL(node->right);
        delete node;
        node = nullptr;
    }
}

// Вставка элемента в дерево
void AVLTree::Insert(int key) {
    InsertAVL(root, key);
}

// Поиск элемента в дереве
bool AVLTree::Search(int key) const {
    return SearchAVL(root, key);
}

// Удаление элемента из дерева
void AVLTree::Delete(int key) {
    DeleteAVLNode(root, key);
}

// Запись дерева в файл
void AVLTree::WriteToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        writeNodeToFile(root, file, 0);
        file.close();
    } else {
        cerr << "Не удалось открыть файл для записи.\n";
    }
}

// Получение минимального значения в дереве
int AVLTree::FindMin() const {
    AVLNode* minNode = MinValueAVLNode(root);
    if (minNode) {
        return minNode->data;
    }
    return -1; // В случае пустого дерева
}

// Печать дерева
void AVLTree::PrintTree() const {
    PrintTreeAVL(root, 0);
}

// Получение высоты дерева
int AVLTree::Height() const {
    return HeightAVL(root);
}
