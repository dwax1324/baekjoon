
a = int(input())

ff = []
for i in range(a):
    a, b = input().split()
    b = int(b)
    ff.append([a, b])

ff = sorted(ff, key=lambda x: (-x[1], x[0]))

print(ff[0][0])
