# 구현
c = int(input())
ff = {}
for i in range(c):
    a, b = input().split('.')
    if b in ff:
        ff[b] += 1
    else:
        ff[b] = 1


ff2 = []
for i in ff:
    ff2.append([i, ff[i]])

ff2 = sorted(ff2, key=lambda x: x[0])

for i in ff2:
    print(i[0], i[1])
