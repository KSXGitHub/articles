
#include <iostream>
#include "avl-tree.hpp"

using namespace std;

typedef int Data;
typedef AVLTree<Data> Tree;

int main();
Tree inputTree();
void viewTree(Tree);

int main() {
    auto tree = inputTree();
    cout << "Cay can bang da nhap:\n";
    viewTree(tree);
    return 0;
}

Tree inputTree() {

    Tree tree;
    unsigned count;

    cout << "Nhap so luong va cac node:";

    for (cin >> count; count; --count) {
        Data data;
        cin >> data;
        tree.addNode(data);
    }

    return tree;

}

void viewTree(Tree tree) {

    for (auto iterator : Tree::Traverse::PreOrder(tree)) {

        // display level
        cout << "> \t";
        for (unsigned count = iterator.level(); count; --count) {
            cout << '\t';
        }

        // display tree
        auto tree = iterator.tree();
        if (tree) {
            cout << tree.data() << endl;
        } else {
            cout << "null\n";
        }

    }

}
