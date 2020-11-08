
# 오른쪽 끝의 타일이 1개일때 , 2개일때를 따져가면서 계산
try:
    ff = [0 for i in range(251)]

    while(1):
        a = int(input())
        ff[0] = 1
        ff[1] = 1
        ff[2] = 3

        for i in range(3, a+1):
            ff[i] = ff[i-1] + 2*ff[i-2]

        print(ff[a])
except:
    exit()
