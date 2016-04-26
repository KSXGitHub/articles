
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
        bool rotate = false;
        _addNode(tree, data, rotate);
    }

    void _viewTree(Tree tree, unsigned level) {

        // display level
        cout << '_';
        for (unsigned count = level; count; --count) {
            cout << '_';
        }

        // display tree
        if (tree) {

            // display data
            cout << tree->data;

            // display branches
            ++level;
            _viewTree(tree->left, level);
            _viewTree(tree->right, level);

        } else {

            cout << 'null';

        }

        // make new line
        cout << endl;

    }

}
