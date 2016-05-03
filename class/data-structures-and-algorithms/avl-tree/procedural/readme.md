
# Thiết kế Cây cân bằng theo mô hình Lập trình hướng thử tục

## Các hàm trong [`AVLTree`](./avl-tree.hpp#L34)

### Hàm xem cây

```c++
void viewTree(Tree);
```

[Xem code](./avl-tree.hpp#L55)

### Hàm thêm node

```c++
void addNode(Tree &, Data);
```

[Xem code](./avl-tree.hpp#L82)

## Chương trình chính - [`main`](./main.cpp#L9)

 * **Nhập cây** bằng vòng lặp và hàm `addNode`

 * **Xem cây** bằng hàm `viewTree`
