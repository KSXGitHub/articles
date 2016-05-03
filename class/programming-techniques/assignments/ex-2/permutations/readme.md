
# Liệt kê tất cả các hoán vị của một tập hợp các phần tử

## Mã giả

```
function permutations(set: Array of Element): Array of Array of Element
    if set.empty(): # -- Điều kiện neo: set là mảng rỗng --
        return [[]]; # Trả về một mảng (2-chiều) chứa một phần tử là một mảng rỗng (1-chiều)
    else:
        var result = []; # Khởi tạo biến result là mảng 2-chiều (kiểu 'Array of Array of Element'), rỗng, dùng để lưu trữ các hoán vị của set
        for i in set: # Duyệt mảng set, các phần tử được lần lượt ghi vào biến i, i có kiểu 'Element'
            var filtered = set.except(i); # Mảng filtered chứa tất cả các phần tử của set ngoại trừ phần tử mà i trỏ tới
            var nextperm = permutations(filtered); # -- ĐỆ QUY --
            for j in nextperm: # Mỗi giá trị của j là một hoán vị của filtered, j là mảng 1-chiều, có kiểu 'Array of Element'
                var addend = concat([i], j); # Mảng addend là một hoán vị của set, có phần tử đầu là i, các phần tử còn lại phía sau là j
                result.add(addend); # Thêm addend vào cuối mảng result
        return result;

```

### Giải thích ký hiệu

 * `[a, b, c]`: Mảng chứa các phần tử `a`, `b`, `c`

 * `if`, `else`: Từ khóa của câu lệnh rẽ nhánh

 * `return`: Trả về kết quả, thoát khỏi hàm

 * `var`: Khai báo biến

 * `array.except(exception)`: Mảng chứa tất cả các phần tử của mảng `array` nhưng không chứa `exception`

 * `concat(a, b)`: Mảng gồm các phần tử của mảng a và mảng b, các phần tử a đứng trước b

## Mã thật

 * [JavaScript](./javascript)
 * [Python](./python)
