# 구현
a = int(input())
for j in range(1, 65):
    sum = 1
    for i in range(1, 65):
        if(i == j):
            sum = sum*2 - 1
        else:
            sum *= 2

    if(sum == a):
        print(j)
        exit()
