
# Mảng động vs mảng tĩnh

## 1. Mảng tĩnh

### 1.1. Khai báo

#### 1.1.1. Cú pháp

```c++
ElementType ArrayName[ArrayLength];
```

Trong đó:
 - `ElementType` là kiểu phần tử
 - `ArrayName` là tên mảng
 - `ArrayLength` là độ dài được bộ nhớ cấp phát cho mảng, độ dài phải là một hằng số nguyên dương

#### 1.1.2. Ví dụ

```c++
int myarray[255];
```

```c++
const unsigned length = 255;
int myarray[length];
```

```c++
typedef int MyArray[255];
MyArray myarray;
```

### 1.2. Duyệt mảng

Ví dụ: Người dùng nhập độ dài và các phần tử của mảng

```c++
const unsigned maxlength = 255;
typedef int Array[maxlength];
void nhapmang(Array array, unsigned &length) {
	std::cin >> length;
	if (length > maxlength) {
		std::cout << "Do dai khong hop le.\n";
		return;
	}
	for (unsigned i = 0; i != length; ++i) {
		std::cin >> array[i];
	}
}
```

```c++
const unsigned maxlength = 255;
typedef int Array[maxlength];
void nhapmang(Array array, int * end) {
	unsigned length;
	std::cin >> length;
	if (length > maxlength) {
		std::cout << "Do dai khong hop le.\n";
		return;
	}
	end = array + length;
	for (int * i = array; i != end; ++i) {
		std::cin >> * i;
	}
}
```

## 2. Mảng tĩnh

### 2.1. Khai báo, khởi tạo, phá hủy

#### 2.1.1. Cú pháp khai báo

**Bản chất:** Khai báo con trỏ

```c++
ElementType *ArrayName;
```

```c++
template <typename type> using pointer = type *;
pointer<ElementType> ArrayName;
```

#### 2.1.2. Cú pháp khởi tạo

**Bản chất:** Gán cho con trỏ một giá trị bằng con trỏ trỏ tới phần tử đầu tiên của một vùng nhớ mới được cấp phát

```c++
ArrayName = new ElementType[ArrayLength];
```

Trong đó:
 - `ArrayLength` là một hằng hoặc biến nguyên dương bất kì

Xem thêm:
 - http://en.cppreference.com/w/cpp/memory/new/operator_new
 - http://www.cplusplus.com/reference/new/operator%20new/

#### 2.1.3. Cú pháp phá hủy

**Bản chất:** Giải phóng vùng nhớ được cấp phát cho mảng động, nhờ vậy, vùng nhớ này (hoặc một phần của nó) có thể được cấp phát lại cho một mảng động khác (khi dùng toán tử `new`)

```c++
delete[] ArrayName;
```

Xem thêm:
 - http://en.cppreference.com/w/cpp/memory/new/operator_delete
 - http://www.cplusplus.com/reference/new/operator%20delete[]/

#### 2.1.4. Ví dụ

```c++
unsigned length;
std::cout << "Nhap do dai.\n";
std::cin >> length;
int *array = new int[length];
nhapmang(array, length);
xuatmang(array, length);
delete[] array;
```

### 2.2. Duyệt mảng

Tương tự mảng tĩnh

## 3. Ví dụ

### 3.1. Bài toán

Nhập số nguyên dương n, và hai mảng A, B có độ dài n. Xuất mảng C = A + B, biết rằng &forall; i &in; (0; +&infin;) &cap; &#x2124;: C<sub>i</sub> = A<sub>i</sub> + B<sub>i</sub>

### 3.2. Codes

 * [Mảng tĩnh](./mang-tinh.cpp)

 * [Mảng động](./mang-dong.cpp)
