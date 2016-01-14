
# Bài toán

![S(x, n) = SUM(i: 0 --> n => x^i/n!)](http://chart.googleapis.com/chart?chs=128&cht=tx&chl=S_%7B%28x%2Cn%29%7D%20%3D%20%5Cbigg%20%5Csum%20_%7Bi%3D0%7D%20%5En%20%5Cfrac%20%7Bx%5Ei%7D%20%7Bi!%7D)

# Phân tích

## I/O

 * Input:
  - Số nguyên không âm `n`
  - Số thực `x`

 * Output:
  - Số thực `S`

## Giải thuật

 * Xem [./main.cpp](./main.cpp) để biết thêm chi tiết

1. Nhập số nguyên không âm n và số thực x

2. S &leftarrow; 1; Tich &leftarrow; 1; GiaiThua &leftarrow; 1; i &leftarrow; 1

3. Nếu i > n, chuyển đến bước 7

4. Tich &leftarrow; Tich &times; x; GiaiThua &leftarrow; GiaiThua &times; i

5. S &leftarrow; S + Tich/GiaiThua

6. i &leftarrow; i + 1; Chuyển đến bước 3

7. Output là S. Kết thúc.
