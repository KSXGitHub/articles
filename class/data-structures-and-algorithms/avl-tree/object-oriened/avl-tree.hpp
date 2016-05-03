
#include <cstdlib>

template <class Data>
class AVLTree {

private:

    /* TYPES AND CLASSES */

    enum Balance {
        LEFT, NOSIDE, RIGHT
    };

    struct Node {

        Data data;
        Node *left, *right;
        Balance balance;

        Node(Data data = Data()) {
            Node::data = data;
            left = right = NULL;
            balance = Balance::NOSIDE;
        }

        ~Node() {
            delete left;
            delete right;
        }

    };

    /* FUNCTIONS */

    void _addNode(Node *&origin, Data data, bool &rotate) {
        if (!origin) {
            origin = new Node(data);
            rotate = true;
        } else if (data < origin->data) {
            _addNode(origin->left, data, rotate);
            if (rotate) switch (origin->balance) {
                case Balance::LEFT:
                    _rotateLeft(origin);
                    origin->balance = Balance::NOSIDE;
                    rotate = false;
                    break;
                case Balance::NOSIDE:
                    origin->balance = Balance::LEFT;
                    break;
                case Balance::RIGHT:
                    origin->balance = Balance::NOSIDE;
                    rotate = false;
                    break;
            }
        } else if (data > origin->data) {
            _addNode(origin->right, data, rotate);
            if (rotate) switch (origin->balance) {
                case Balance::LEFT:
                    origin->balance = Balance::NOSIDE;
                    rotate = false;
                    break;
                case Balance::NOSIDE:
                    origin->balance = Balance::RIGHT;
                    break;
                case Balance::RIGHT:
                    _rotateRight(origin);
                    origin->balance = Balance::NOSIDE;
                    rotate = false;
            }
        } else {
            rotate = false;
        }
    }

    void _rotateLeft(Node *&origin) {
        Node *p1 = origin->left;
        if (p1->balance == Balance::LEFT) {
            origin->left = p1->right;
            p1->right = origin;
            origin = p1;
        } else {
            Node *p2 = p1->right;
            origin->left = p2->right;
            p1->right = p2->left;
            p2->left = p1;
            p2->right = origin;
            switch (p2->balance) {
                case Balance::LEFT:
                    p1->balance = Balance::RIGHT;
                    origin->balance = Balance::NOSIDE;
                    break;
                case Balance::RIGHT:
                    p1->balance = Balance::NOSIDE;
                    origin->balance = Balance::LEFT;
                    break;
                default:
                    p1->balance = origin->balance = Balance::NOSIDE;
            }
            origin = p2;
        }
    }

    void _rotateRight(Node *&origin) {
        Node *p1 = origin->right;
        if (p1->balance == Balance::RIGHT) {
            origin->right = p1->left;
            p1->left = origin;
            origin = p1;
        } else {
            Node *p2 = p1->left;
            origin->right = p2->left;
            p1->left = p2->right;
            p2->right = p1;
            p2->left = origin;
            switch (p2->balance) {
                case Balance::RIGHT:
                    p1->balance = Balance::LEFT;
                    origin->balance = Balance::NOSIDE;
                    break;
                case Balance::LEFT:
                    p1->balance = Balance::NOSIDE;
                    origin->balance = Balance::RIGHT;
                    break;
                default:
                    p1->balance = origin->balance = Balance::NOSIDE;
            }
            origin = p2;
        }
    }

    /* DATA */

    Node *origin;

public:

    /* TYPES AND CLASSES */

    struct TRAVERSE {
        struct Order {};
        struct PreOrder : Order {};
        struct MidOrder : Order {};
        struct PostOrder : Order {};
        typedef void (*OnNode)(Data *, unsigned);
        typedef void (*OnNull)(unsigned);
        static constexpr auto PRE_ORDER = PreOrder();
        static constexpr auto MID_ORDER = MidOrder();
        static constexpr auto POST_ORDER = PostOrder();
    };

    /* CONSTRUCTORS */

    AVLTree(Node *origin = NULL) {
        AVLTree::origin = origin;
    }

    ~AVLTree() {
        delete origin;
    }

    /* FUNCTIONS */

    auto data() {
        return origin->data;
    }

    auto data(Data value) {
        origin->data = value;
        return this;
    }

    auto left() {
        return AVLTree(origin->left);
    }

    auto left(AVLTree tree) {
        origin->left = tree.origin;
    }

    auto right() {
        return AVLTree(origin->right);
    }

    auto right(AVLTree tree) {
        origin->right = tree.origin;
    }

    void addNode(Data data) {
        bool rotate = false;
        _addNode(origin, data, rotate);
    }

    void traverse(typename TRAVERSE::PreOrder order, typename TRAVERSE::OnNode onnode, typename TRAVERSE::OnNull onnull, unsigned level = 0) {
        if (origin) {
            onnode(&origin->data, level);
            left().traverse(order, onnode, onnull, level + 1);
            right().traverse(order, onnode, onnull, level + 1);
        } else {
            onnull(level);
        }
    }

    void traverse(typename TRAVERSE::MidOrder order, typename TRAVERSE::OnNode onnode, typename TRAVERSE::OnNull onnull, unsigned level = 0) {
        if (origin) {
            left().traverse(order, onnode, onnull, level + 1);
            onnode(&origin->data, level);
            right().traverse(order, onnode, onnull, level + 1);
        } else {
            onnull(level);
        }
    }

    void traverse(typename TRAVERSE::PostOrder order, typename TRAVERSE::OnNode onnode, typename TRAVERSE::OnNull onnull, unsigned level = 0) {
        if (origin) {
            left().traverse(order, onnode, onnull, level + 1);
            right().traverse(order, onnode, onnull, level + 1);
            onnode(&origin->data, level);
        } else {
            onnull(level);
        }
    }

};
