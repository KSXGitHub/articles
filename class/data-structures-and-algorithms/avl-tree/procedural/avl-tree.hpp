
#include <cstdlib>
#include <iostream>

namespace AVLTree {

    /* IMPORT NAMESPACES */

    using namespace std;

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
        ~Node() {
            delete left;
            delete right;
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
        cout << "> \t";
        for (unsigned count = level; count; --count) {
            cout << '\t';
        }

        // display tree
        if (tree) {

            // display data
            cout << tree->data << endl;

            // display branches
            ++level;
            _viewTree(tree->left, level);
            _viewTree(tree->right, level);

        } else {

            cout << "null\n";

        }

    }

    void _addNode(Tree &tree, Data data, bool &rotate) {
        if (!tree) {
            tree = new Node(data);
            rotate = true;
        } else if (data < tree->data) {
            _addNode(tree->left, data, rotate);
            if (rotate) switch (tree->bal) {
                case -1:
                    _rotateLeft(tree);
                    tree->bal = 0;
                    rotate = false;
                    break;
                case 0:
                    tree->bal = -1;
                    break;
                case 1:
                    tree->bal = 0;
                    rotate = false;
                    break;
            }
        } else if (data > tree->data) {
            _addNode(tree->right, data, rotate);
            if (rotate) switch (tree->bal) {
                case -1:
                    tree->bal = 0;
                    rotate = false;
                    break;
                case 0:
                    tree->bal = 1;
                    break;
                case 1:
                    _rotateRight(tree);
                    tree->bal = 0;
                    rotate = false;
            }
        } else {
            rotate = false;
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
            origin->left = p2->right;
            p1->right = p2->left;
            p2->left = p1;
            p2->right = origin;
            switch (p2->bal) {
                case -1:
                    p1->bal = 1;
                    origin->bal = 0;
                    break;
                case 1:
                    p1->bal = 0;
                    origin->bal = -1;
                    break;
                default:
                    p1->bal = origin->bal = 0;
            }
            origin = p2;
        }
    }

    void _rotateRight(Tree &origin) {
        Tree p1 = origin->right;
        if (p1->bal == 1) {
            origin->right = p1->left;
            p1->left = origin;
            origin = p1;
        } else {
            Tree p2 = p1->left;
            origin->right = p2->left;
            p1->left = p2->right;
            p2->right = p1;
            p2->left = origin;
            switch (p2->bal) {
                case 1:
                    p1->bal = -1;
                    origin->bal = 0;
                    break;
                case -1:
                    p1->bal = 0;
                    origin->bal = 1;
                    break;
                default:
                    p1->bal = origin->bal = 0;
            }
            origin = p2;
        }
    }

}
