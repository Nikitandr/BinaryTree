#pragma once
#include <iostream>

using namespace std;

class Node {
public:
    int key;

    Node* left;
    Node* right;
    Node* parent;

    Node(int key_P) : key(key_P), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Сервисный метод для удаления дерева под узлом
    void remove(Node* node);

public:
    BinaryTree() : root(nullptr) {}

    Node* getRoot() const { return root; }

    // Поиск узла с минимальным значением ключа
    Node* min(Node* node) const;

    // Поиск узла с максимальным значением ключа
    Node* max(Node* node) const;

    // Следующий узел
    Node* next(Node* node) const;

    // Предыдущий узел
    Node* prev(Node* node) const;

    // Поиск узла по ключу
    Node* search(Node* node, int key) const;

    // Печать дерева под узлом
    void print(Node* node) const;

    // Вставка узла
    void insert(int value);
    
    // Удаление дерева от указанного узла
    void remove_tree(Node* node);

    // Удаление узла из дерева
    void remove_node(Node*& node);

    ~BinaryTree();
};
