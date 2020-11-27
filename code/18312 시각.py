# 구현

h = 0
m = 0
s = 0
n, k = map(int, input().split())
cnt = 0


def check(a):
    global k
    z = str(a).zfill(2)

    if(z[0] == str(k) or z[1] == str(k)):
        return True
    return False


# f = open("pyopen.txt", 'w')
while(True):
    if(h == n+1 and m == 0 and s == 0):
        break
    # f.write(str(h))
    # f.write(' ')
    # f.write(str(m))
    # f.write(' ')
    # f.write(str(s))
    # f.write('\n')
    s += 1
    if(check(s) or check(m) or check(h)):
        cnt += 1
    if(s == 60):
        m += 1
        s = 0
    if(m == 60):
        h += 1
        m = 0
print(cnt)
# f.close()
