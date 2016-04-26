
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
        _addNode(tree, data);
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

    void _addNode(Tree &tree, Data data) {
        if (tree) {
            tree = new Node(data);
        } else if (data < tree->data) {
            _addNode(tree->left, data);
            if (tree->bal) {
                if (tree->bal == -1) {
                    _rotateLeft(tree);
                }
                tree->bal = 0;
            } else {
                tree->bal = -1;
            }
        } else if (data > tree->data) {
            _addNode(tree->right, data);
            if (tree->bal) {
                if (tree->bal == 1) {
                    _rotateRight(tree);
                }
                tree->bal = 0;
            } else {
                tree->bal = 1;
            }
        }
    }

    void _rotateLeft(Tree &origin) {
        Tree p1 = origin->left;
        if (p1->bal == -1) {
            origin->left = p1->right;
            p1->right = origin;
            origin = p1;
        } else {
            Tree p2 = p1->right;
            origin->left = p1->right;
            p2->right = p;
            p1->right = p2->left;
            p2->left = p1;
            // I'll handle it myself
        }
    }

}
