#! /usr/bin/env python

from permutations import permutations
from sys import argv

count = int(input("Nhap so luong cac phan tu cua moi hoan vi: ") if argv.__len__() == 1 else argv[1])

if count < 0:
    raise "So luong phan tu moi hoan vi phai la mot so tu nhien"

pattern = set(range(0, count));

print("Tat ca cac hoan vi cua", pattern)

i = 0
for order in permutations(pattern):
    print(i, "\t", order)
    i += 1
