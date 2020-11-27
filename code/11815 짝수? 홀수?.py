# 구현


n = int(input())
ff = list(map(int, input().split()))

for ffi in ff:
    k = ffi**0.5
    if(int(k)*int(k) == ffi):
        print(1, end=" ")
    else:
        print(0, end=" ")
