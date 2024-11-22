#include "BinaryTree.h"

int main() {
    setlocale(LC_ALL, "Rus");

    BinaryTree tree;

    // Пример работы
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);

    cout << "Дерево: ";
    tree.print(tree.getRoot());
    cout << "\n";

    Node* root = tree.getRoot();
    cout << "Минимум: " << tree.min(root)->key << "\n";
    cout << "Максимум: " << tree.max(root)->key << "\n";

    Node* searchNode = tree.search(root, 10);
    if (searchNode) {
        cout << "Следующий после 10: " << (tree.next(searchNode) ? tree.next(searchNode)->key : -1) << "\n";
        cout << "Предыдущий до 10: " << (tree.prev(searchNode) ? tree.prev(searchNode)->key : -1) << "\n";
    }

    cout << "Удаление ветки с корнем 10\n";
    tree.remove_tree(searchNode);

    cout << "Дерево после удаления: ";
    tree.print(tree.getRoot());

    return 0;
}
