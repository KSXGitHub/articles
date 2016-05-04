
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

    cout << "Nhap so luong va cac node: ";

    for (cin >> count; count; --count) {
        Data data;
        cin >> data;
        tree.addNode(data);
    }

    return tree;

}

void viewTree(Tree tree) {

    auto outlv = [](unsigned level) {
        cout << "> \t";
        for ( ; level; --level) {
            cout << '\t';
        }
    };

    auto onnode = [outlv](Data *pointer, unsigned level) {
        outlv(level);
        cout << *pointer << endl;
    };

    auto onnull = [outlv](unsigned level) {
        outlv(level);
        cout << "null\n";
    };

    tree.traverse(Tree::TRAVERSE::PRE_ORDER, onnode, onnull);

}
