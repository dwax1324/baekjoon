# 구현
a = int(input())
for i in range(a):
    ff = [0 for i in range(26)]
    b = input()
    for bj in b:
        if(ord(bj) >= 97 and ord(bj) <= 122):
            ff[ord(bj)-97] += 1

    if(ff.count(max(ff)) == 1):
        for i in range(len(ff)):
            if ff[i] == max(ff):
                print(chr(i+97))
                break

    else:
        print("?")
