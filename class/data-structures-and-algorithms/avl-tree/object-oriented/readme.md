
# Thiết kế Cây cân bằng theo mô hình Lập trình hướng đối tượng

## Yêu cầu trình dịch

 * Hỗ trợ C++14

## Thiết kế chung của Lớp [`AVLTree`](./avl-tree.hpp#L4-L225)

```c++
template <class Data>
struct AVLTree {

    // Các phương thức (thứ tự) duyệt cây nhị phân
    struct TRAVERSE {
        struct Order;
        struct PreOrder : Order; // NLR: Gốc - Trái - Phải
        struct InOrder : Order; // LNR: Trái - Gốc - Phải
        struct PostOrder : Order; // LRN: Trái - Phải - Gốc
        static constexpr auto PRE_ORDER = PreOrder();
        static constexpr auto IN_ORDER = InOrder();
        static constexpr auto POST_ORDER = PostOrder();
    };

    // Các hàm kiến tạo, phá hủy (constructor, destructor)
    AVLTree();
    ~AVLTree();

    // Các hàm lấy/gán dữ-liệu/nhánh
    Data data(); // Lấy dữ liệu
    void data(Data); // Gán dữ liệu
    AVLTree left(); // Lấy nhánh trái
    void left(AVLTree); // Gán nhánh trái
    AVLTree right(); // Lấy nhánh phải
    void right(AVLTree); // Gán nhánh phải

    // Hàm thêm node vào cây
    void addNode(Data);

    // Các hàm duyệt cây theo các thứ tự tương ứng
    template <class OnNode, class OnNull> void traverse(typename TRAVERSE::PreOrder, OnNode, OnNull);
    template <class OnNode, class OnNull> void traverse(typename TRAVERSE::InOrder, OnNode, OnNull);
    template <class OnNode, class OnNull> void traverse(typename TRAVERSE::PostOrder, OnNode, OnNull);

};
```

## Chương trình chính - [`main`](./main.cpp#L14-L19)

 * **Kiểu dữ liệu** được sử dụng: Cây cân bằng của các `int` ([`Data`](./main.cpp#L7)|[`Tree`](./main.cpp#L8))

 * **Nhập cây** bằng vòng lặp và phương thức [`Tree::addNode`](./avl-tree.hpp#L187-L190) hay [`Tree::_addNode`](./avl-tree.hpp#L36-L74) ([`inputTree`](./main.cpp#L21-36))

 * **Xem cây** ([`viewTree`](./main.cpp#L38-L59)) bằng cách *duyệt cây* theo thứ tự NLR ([`traverse`](./avl-tree.hpp#L192-L201))
