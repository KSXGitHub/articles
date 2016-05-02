
import permutations from permutations

count = int(input("Nhap so luong cac phan tu cua moi hoan vi: "));

if count < 0:
    raise "So luong phan tu moi hoan vi phai la mot so tu nhien"

pattern = [];
i = 0;
while i != count:
    pattern += [i]
    i += 1
    pass

print("Tat ca cac hoan vi:")
print(permutations(pattern))
