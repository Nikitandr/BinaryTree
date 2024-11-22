#include "BinaryTree.h"

void BinaryTree::remove(Node* node) {
    if (node) {
        remove(node->left);
        remove(node->right);
        delete node;
    }
}

Node* BinaryTree::min(Node* node) const {
    while (node && node->left)
    {
        node = node->left;
    }

    return node;
}

Node* BinaryTree::max(Node* node) const {
    while (node && node->right)
    {
        node = node->right;
    }

    return node;
}

Node* BinaryTree::next(Node* node) const {
    // Завершаем работу, если node пуст
    if (!node) return nullptr;

    Node* parent = nullptr;

    if (node->right) {
        return min(node->right);
    }

    parent = node->parent;

    while (parent && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* BinaryTree::prev(Node* node) const {
    // Завершаем работу, если node пуст
    if (!node) return nullptr;

    Node* parent = nullptr;

    if (node->left) {
        return max(node->left);
    }

    parent = node->parent;

    while (parent && node == parent->left) {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

Node* BinaryTree::search(Node* node, int key) const
{
    while (node)
    {
        if (key == node->key)
        {
            return node;
        }

        // Переход в левую ветку, если искомый ключ меньше значения в текущем узле, и в правую - если больше
        node = (key < node->key) ? node->left : node->right;
    }

    return nullptr;
}

void BinaryTree::print(Node* node) const
{
    // Завершаем работу, если node пуст
    if (!node) return;

    print(node->left);

    cout << node->key << " ";

    print(node->right);
}

void BinaryTree::insert(int value)
{
    Node* newNode = new Node(value);
    Node* current = root;
    Node* parent = nullptr;

    if (!root) {
        root = newNode;
        return;
    }

    while (current) {
        parent = current;

        if (value < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (value < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

void BinaryTree::remove_tree(Node* node) {
    // Завершаем работу, если node пуст
    if (!node) return;

    if (node == root) {
        remove(root);
        root = nullptr;
    }
    else {
        // Если указан не корень
        // Удаляем у родителя связь с текущим узлом
        if (node->parent->left == node) {
            node->parent->left = nullptr;
        }
        else {
            node->parent->right = nullptr;
        }

        remove(node);
    }
}

void BinaryTree::remove_node(Node*& node)
{
    // Завершаем работу, если node пуст
    if (!node) return;

    // Проверка узлов с одним потомком или вообще без потомков
    // Если левой ветки нет
    if (!node->left)
    {
        // Переходим в правую ветку
        Node* temp = node->right;

        // Если она существует
        if (temp)
        {
            // Указателю на родителя правой ветки присваиваем адрес родителя удаляемого узла
            temp->parent = node->parent;
        }

        delete node;

        // Присваиваем указателю адрес нового узла, так как после удаления он указывает в пустоту
        node = temp;
    }
    // Если правой ветки нет
    else if (!node->right)
    {
        // Переходим в левую ветку
        Node* temp = node->left;

        // Если она существует
        if (temp)
        {
            // Указателю на родителя левой ветки присваиваем адрес родителя удаляемого узла
            temp->parent = node->parent;
        }

        delete node;

        // Присваиваем указателю адрес нового узла, так как после удаления он указывает в пустоту
        node = temp;
    }
    else
    {
        // Если у узла два потомка, то удалить его невозможн
        // Поэтому находим следующий элемент
        Node* next_node = next(node);

        // Выполняем полное копирование информации из следующего узла в текущий
        // В данном случае копируется только ключ, так как больше в узле информации нет
        node->key = next_node->key;

        // Когда вся информация из следующего узла скопирована, удаляем его
        remove_node(next_node);
    }
}

BinaryTree::~BinaryTree() {
    remove(root);
}