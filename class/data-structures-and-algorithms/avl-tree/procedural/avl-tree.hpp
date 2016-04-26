
#include <cstdlib>
#include <iostream>

namespace AVLTree {

    /* TYPES AND CLASSES */

    typedef int Data;

    struct Node {
        Data data;
        Node *left, *right;
        int bal;
        Node(Data data = 0) {
            Node::data = data;
            left = right = NULL;
            bal = 0;
        }
    };

    typedef Node *Tree;

    /* FUNCTION PROTOTYPES */

    // public
    void viewTree(Tree);
    void addNode(Tree &, Data);

    // private
    void _viewTree(Tree, unsigned);
    void _addNode(Tree &, Data, bool &);
    void _rotateLeft(Tree &);
    void _rotateRight(Tree &);

    /* FUNCTION DEFINITIONS */

    void viewTree(Tree tree) {
        _viewTree(tree, 0);
    }

    void addNode(Tree &tree, Data data) {
        bool rotate = true;
        _addNode(tree, data, rotate);
    }

}
