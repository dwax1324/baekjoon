# 구현
# 초침시침
a, b = map(float, input().split())
ff = [[i*0.5, (i*6) % 360]for i in range(0, 721)]

c = False
for i in ff:
    if(i[0] == a and i[1] == b):
        c = True
if(c == True):
    print("O")
else:
    print("X")

# print(180 0)
