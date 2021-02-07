cnt = 0
a = int(input())
if (a < 0):
    print(32)
    exit()
a = abs(a)
if(a == 0):
    print(1)
    exit()

while(True):
    if(a == 0):
        break
    a //= 2
    cnt += 1

print(cnt)
