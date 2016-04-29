
#include <cstdlib>
#include <iostream>
#include "avl-tree.hpp"

using namespace std;
using namespace AVLTree;

int main() {
    Tree tree = NULL;
    unsigned count;
    cout << "Nhap so luong va cac node: ";
    for (cin >> count; count; --count) {
        Data data;
        cin >> data;
        addNode(tree, data);
    }
    cout << "Cay can bang da nhap:\n";
    viewTree(tree);
    delete tree;
    return 0;
}
