
# Thiết kế Cây cân bằng theo mô hình Lập trình hướng thử tục

## Yêu cầu trình dịch

 * Hỗ trợ C++98

## Các hàm trong [`AVLTree`](./avl-tree.hpp#L34-L36)

### Hàm xem cây

```c++
void viewTree(Tree);
```

[Xem code](./avl-tree.hpp#L55-L80)

### Hàm thêm node

```c++
void addNode(Tree &, Data);
```

[Xem code](./avl-tree.hpp#L82-L120)

## Chương trình chính - [`main`](./main.cpp#L9-L22)

 * **Nhập cây** bằng vòng lặp và hàm `addNode`

 * **Xem cây** bằng hàm `viewTree`
